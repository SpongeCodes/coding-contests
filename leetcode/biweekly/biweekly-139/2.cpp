#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<pair<int,pair<int,int>>> pq;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        pq.push({health-grid[0][0],{0,0}});
        while(!pq.empty()) {
            auto p  = pq.top().second;
            int x = p.first, y = p.second;
            int h = pq.top().first;
            pq.pop();
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            if(x==n-1 && y==m-1) return true;
            for(auto &d: dir) {
                int nx = x+d[0], ny=y+d[1];
                if(nx<0 || nx >=n || ny<0 || ny>=m) continue;
                if(!vis[nx][ny] && h-grid[nx][ny]>0)
                    pq.push({h-grid[nx][ny],{nx,ny}});
            }
        }
        return false;

    }
};