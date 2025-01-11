#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<string> grid;
    string s;
    while(getline(cin,s)) {
        grid.push_back(s);
    }
    int H = grid.size(), W = grid[0].size();
    pair<int,int> start, end;
    for(int i=0;i<H;++i) {
        for(int j = 0 ; j<W;++j) {
            if(grid[i][j] == 'S') {
                start = {i,j};
            }
            if(grid[i][j] == 'E') {
                end = {i,j};
            }
        }
    }
    vector<pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    auto inside = [&](int x,int y) {
        return (0<=x && x<H && 0<=y && y<W);
    };
    auto bfs = [&](pair<int,int> src) {
        vector<vector<int>> v(H,vector<int>(W,1E9+5));
        queue<pair<int,int>> q;
        q.push(src);
        v[src.first][src.second] = 0;
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int r = curr.first, c = curr.second;
            if(grid[r][c] == '#') continue;
            for(auto [dx,dy] : dirs) {
                int r2 = r + dx, c2 = c + dy;
                if(inside(r2,c2) && v[r2][c2] > 1+v[r][c]) {
                    v[r2][c2] = 1 + v[r][c];
                    q.push({r2,c2});
                }
            }
        }
        return v;
    };

    vector<vector<int>> a = bfs(start), b = bfs(end);
    int normal = a[end.first][end.second];
    // for for 
    int res = 0;
    for(int r=0;r<H;++r) {
        for(int c = 0; c<W ; ++c) {
            if(grid[r][c]=='#') {
                for(auto [dx,dy]: dirs) {
                    int r2 = r + dx, c2 = c+dy;
                    if(inside(r2,c2) && grid[r2][c2] != '#') {
                        int here = a[r][c] + 1 + b[r2][c2];
                        if(here <= normal-100) res++;
                    } 
                }
            }
        }
    }
    cout<<res<<endl;
}