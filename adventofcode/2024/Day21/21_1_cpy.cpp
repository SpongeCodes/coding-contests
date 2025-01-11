#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9+5;
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

ll dist[5][5][5][11];
bool vis[5][5][5][11];

const char MOVEMENT = '$', ERROR = '@';

pair<int,int> f(pair<int,int> me, int dir) {
    assert(0<=dir && dir<4);
    return {me.first + dirs[dir].first, me.second + dirs[dir].second};
}

char getCh(int value) {
    if(value>=0 && value<10) return '0'+value;
    if(value == 10) return 'A';
    return false;
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


char apply(int move, int i, array<int,4> &state) {
    if(move == HIT) {
        if(i==3) {
            // you are printing a character from numpad
            return getCh(state[3]);
        }
        // apply position on next robot
        return apply(state[i],i+1,state);
    }
    // movement from a previous hit or from human
    return makeMove(move,state[i], (i==3? numpad:dpad));

}

int main()
{
    // state is (chars entered, r1,r2,r3)
    // character can be entered only if r3 is on a character and r1==r2==HIT
    string code;
    ll res = 0;

    while (getline(cin, code))
    {
        ll num = (code[0]-'0') * 100 + (code[1]-'0') * 10 + (code[2]-'0');
        memset(dist,0,sizeof(dist));
        memset(vis,0,sizeof(vis));
        dist[0][HIT][HIT][10] = 0;
        vis[0][HIT][HIT][10] = 1;
        vector<array<int,4>> q;
        q.push_back({0, HIT, HIT, 10});
        for (int z = 0; z < (int) q.size(); z++)
        {
            int chars = q[z][0];
            int r1 = q[z][1], r2 = q[z][2] , r3 = q[z][3];
            //cout<<"{chars = "<<chars<<" s1 =  "<<r1<<" s2 = "<<r2<<" s3 = "<<r3<<" }"<<endl;
            if (chars == (int)code.length())
            {
                res += num * dist[chars][r1][r2][r3];
                break;
            }
            for (int move = 0; move < 5; ++move)
            {
                array<int,4> a  = q[z];
                char pr = apply(move, 1, a);
                if (pr == ERROR)
                    continue;
                if (pr != MOVEMENT)
                {
                    if (pr != code[chars])
                        continue;
                    // cout<< 1 + dist[chars][r1][r2][r3]<<endl;
                }
                int s1 = chars + (pr != MOVEMENT);
                int s2 = a[1], s3 = a[2], s4 = a[3];
                if (!vis[s1][s2][s3][s4])
                {
                    //cout<<"next {s1 = "<<s1<<" s2 = "<<s2<<" s3 = "<<s3<<" s4 = "<<s4<<" }"<<endl;
                    vis[s1][s2][s3][s4] = true;
                    dist[s1][s2][s3][s4] = dist[chars][r1][r2][r3] + 1;
                    //if(s1== 0 && s2==DOWN && s3==HIT && s4 == 10) cout<<dist[s1][s2][s3][s4]<<endl;
                    //cout<<dist[s1][s2][s3][s4]<<endl;
                    q.push_back({s1, s2, s3, s4});
                }
            }
        }
        //cout<<dist[1][HIT][HIT][0]<<endl;
    }
    cout << res << endl;
}