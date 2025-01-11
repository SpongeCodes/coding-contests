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
            for(auto &d: dirs) {
                int ni = i + d.first, nj = j + d.second;
                if(!inside(ni,nj) || grid[ni][nj] != grid[i][j]) perimeter++;
                else q.push({ni,nj});
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