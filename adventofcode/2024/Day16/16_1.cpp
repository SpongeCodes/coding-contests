#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct State {
    int x,y;
    char dir;
    bool operator <(const State & other) const {
        return make_pair(x,make_pair(y,(int)dir)) < make_pair(other.x,make_pair(other.y,(int)other.dir));
    }
};

int main() {
    vector<string> grid;
    string row;
    while(getline(cin,row)) {
        grid.push_back(row);
    }
    int H = grid.size(), W = grid[0].size();
    pair<int,int> src,target;
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;++j) {
            if(grid[i][j]=='S') {
                grid[i][j] = '.';
                src = {i,j};
            }
            if(grid[i][j]=='E') {
                grid[i][j] = '.';
                target = {i,j};
            }
        }
    }
    map<char,int> dir;

    dir['N'] = 0, dir['E'] = 1, dir['S'] = 2, dir['W'] = 3;
    State start{src.first,src.second,'E'};
    auto getTurns = [&](char c1, char c2) {
        int d = abs(dir[c1]-dir[c2]);
        return min(d,4-d)*1000;
    } ;
    auto getDir = [](char c) -> pair<int,int> {
        switch(c) {
            case 'N': return {-1,0};
            case 'E': return {0,1};
            case 'S': return {1,0};
            case 'W': return {0,-1};
        }
        assert(false);
    };
    // dijkstra algorithm
    map<State, ll> distance;
    set<pair<int,State>> s;
    s.insert(make_pair(0,start));
    distance[start] = 0;
    while(!s.empty()) {
        int dist = s.begin()->first;
        State st = s.begin()->second;
        s.erase(s.begin());
        // iterate over all directions
        for(char c: {'N','E','S','W'}) {
            pair<int,int> d = getDir(c);
            int row = st.x + d.first;
            int col = st.y + d.second;
            if(grid[row][col]=='#') continue;
            State now{row,col,c};
            if(!distance.count(now) || distance[now] > dist + 1 + getTurns(c,st.dir)) {
                distance[now] = dist + 1 + getTurns(c,st.dir);
                s.insert(make_pair(distance[now],State{row,col,c}));
            }
        }
    }
    
    ll res = INT_MAX;
    for(char c: {'N','E','S','W'}) {
        State targetState{target.first,target.second,c};
        if(distance.count(targetState))
            res = min(res,distance[State{target.first,target.second,c}]);
    }
    cout<<res<<endl;
}