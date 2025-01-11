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

void dfs(State curr,map<State,vector<State>> &par,set<State> &st,vector<vector<bool>> &vis) {
    if(st.count(curr)) return;
    st.insert(curr);
    int x = curr.x, y = curr.y;
    char dir = curr.dir;
    vis[x][y]  = true;
    for(State parent: par[curr]) {
        dfs(parent,par,st,vis);
    }
}

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
    // PART 2 can use dijkstra algorithm maintaining possible parents and 
    // then dfs from destination
    map<State, ll> distance;
    set<pair<int,State>> s;
    map<State,vector<State>> par;
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
                par.erase(now);
                par[now].push_back(State{st.x,st.y,st.dir});
            }
            else if(distance[now] == dist + 1 + getTurns(c,st.dir)) {
                par[now].push_back(State{st.x,st.y,st.dir});
            }
        }
    }
    
    // do dfs
    ll dist = INT_MAX;
    for(char c: {'N','E','S','W'}) {
        State targetState{target.first,target.second,c};
        if(distance.count(targetState))
            dist = min(dist,distance[State{target.first,target.second,c}]);
    }
    vector<vector<bool>> vis(H,vector<bool>(W));
    for(char c: {'N','E','S','W'}) {
        State st {target.first,target.second,c};
        set<State> s;
        if(distance.count(st) && distance[st]==dist) {
            dfs(st,par,s,vis);
        }
    }
    //cout<<"dist = "<<dist<<endl;
    int res = 0;
    vector<string> newGrid = grid;
    for(int i=0;i<H;++i) {
        for(int j=0;j<W;++j) {
            res += vis[i][j];
            if(vis[i][j]) newGrid[i][j] = 'O';
        }
    }
    // print the possible paths in grid
    for(auto &x: newGrid) {
        cout<<x<<endl;
    }
    cout<<res<<endl;
}