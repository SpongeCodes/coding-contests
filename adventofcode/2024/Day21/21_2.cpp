#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

const ll INF = 1e18+5;
const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3, HIT=4;

pair<int,int> dirs[4] = {{-1,0},{1,0},{0,-1},{0,1}};

vector<vector<int>> numpad = {
    {7,8,9},
    {4,5,6},
    {1,2,3},
    {-1,0,10}
};

vector<vector<int>> dpad = {    
    {-1,UP,HIT},
    {LEFT,DOWN,RIGHT}
};

const int M = 2;
ll dp[M+2][11][11];

const char MOVEMENT = '$', ERROR = '@';

char getCh(int value) {
    if(value>=0 && value<10) return '0'+value;
    if(value == 10) return 'A';
    return false;
}

int getInt(char ch) {
    if(ch>='0' && ch<='9') return ch-'0';
    return 10;
}

char makeMove(int move,int &st, vector<vector<int>> &v) {
    int H = v.size(), W = v[0].size();
    for(int r= 0 ; r < H ; ++r) {
        for(int c = 0 ; c < W ; ++c) {
                if(v[r][c] == st) {
                    r += dirs[move].first;
                    c += dirs[move].second;
                    if(0<=r && r<H && 0<=c && c<W && v[r][c]!=-1) {
                         st = v[r][c];
                         return MOVEMENT;
                    }
                    return ERROR;
                }
        }
    }
    return false;
}

void preprocess() {
    // dp[0][...][...] is 0 because it does not take any previous moves to press on our direction pad
    // dp[index][A][B] -> number of moves to move index-th robot from A to B given all previous robots start
    // from HIT position with all previous robots finally at HIT position
    // dp[i+1][j1][j2] = dp[i][HIT][k1] + 1 + dp[i][k1][k2] + 1 + dp[i][k2][HIT] (last term is to bring ith robot back to HIT position)
    for(int id = 1 ; id<=M+1 ;++id) {
        const int X = (id == M+1)? 11:5;
        for(int from = 0; from < X; ++from) {
            vector<vector<ll>> small(5,vector<ll>(11,INF));
            small[HIT][from] = 0;
            set<pair<ll,pair<int,int>>> pq;
            pq.insert({0,{HIT,from}}); 
            auto consider = [&](int prev, int me, ll maybe) {
                if(maybe < small[prev][me]) {
                    pq.erase({small[prev][me],{prev,me}});
                    small[prev][me] = maybe;
                    pq.insert({maybe,{prev,me}});
                }
            };
            while(!pq.empty()) {
                ll dist = pq.begin()->first;
                int prev = pq.begin()->second.first;
                int me = pq.begin()->second.second;
                pq.erase(pq.begin());
                for(int prev2=0; prev2<5;++prev2) {
                    ll maybe = dist + dp[id-1][prev][prev2];
                    consider(prev2,me,maybe);
                }
                if(prev != HIT) {
                    if(MOVEMENT == makeMove(prev,me,(id==M+1? numpad:dpad))) {
                        consider(prev,me,dist+1);
                    }
                }
            }

            for(int to = 0; to < (id == M+1 ? 11:5) ; ++to) {
                dp[id][from][to]  = small[HIT][to];
            }

        }
    }
}

ll solve(string code) {
    ll total = 0;
    char prev = 'A';
    for(char c: code) {
        total += dp[M+1][getInt(prev)][getInt(c)] + 1;
        prev = c;
    }

    return total;
}

int main()
{
    // state is (chars entered, r1,r2,r3)
    // character can be entered only if r3 is on a character and r1==r2==HIT
    string code;
    ll res = 0;
    preprocess();

    while (getline(cin, code))
    {
        ll num = (code[0]-'0') * 100 + (code[1]-'0') * 10 + (code[2]-'0');
        ll steps = solve(code);
        res += steps*num;
    }
    cout << res << endl;
}