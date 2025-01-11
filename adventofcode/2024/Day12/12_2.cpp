#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<string> grid;
    string s;
    while(getline(cin,s)) {
        grid.push_back(s);
    }
    const int H = grid.size(), W= grid[0].size();
    // do a bfs and get area and perimeter
    vector<vector<bool>> vis(H,vector<bool>(W,0));
    auto inside = [&] (int i, int j) {
        return i>=0 && i<H && j>=0 && j<W;
    };

    auto bfs = [&](int i, int j,int &perimeter, int &area) {
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            if(vis[i][j]) continue;
            area++;
            vis[i][j] = true;

            auto good = [&](pair<int,int> dir) {
                int i1 = i+dir.first, j1 = j+dir.second;
                return inside(i1,j1) && grid[i1][j1]==grid[i][j];

            };

            for(int m=0;m<4;++m) {
                pair<int,int> dir1 = dirs[m];
                pair<int,int> dir2 = dirs[(m+1)%4];
                if(!good(dir1) && !good(dir2)) perimeter++;
                if(good(dir1) && good(dir2) && !good({dir1.first+dir2.first,dir1.second+dir2.second})) perimeter++;
            }

            for(auto &d: dirs) {
                int ni = i + d.first, nj = j + d.second;
                if(inside(ni,nj) && grid[ni][nj] == grid[i][j]) q.push({ni,nj});
            }
        }
    };

    ll res = 0;
    for(int i= 0 ; i<H; ++i) {
        for(int j=0; j<W; ++j) {
            if(!vis[i][j]) {
                int perimeter = 0, area= 0 ;
                bfs(i,j,perimeter,area);
                res += area*perimeter;
            }
        }   
    }
    cout<<res<<endl;

}