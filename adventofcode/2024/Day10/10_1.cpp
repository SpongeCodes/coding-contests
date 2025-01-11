#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll TIME = 1;

bool inside(int i, int j,const int &H, const int &W) {   
        return i>=0 && i<H && j>=0 && j<W;
}

void dfs(int i,int j,const int &H, const int &W, vector<string> &grid,vector<vector<int>> &vis,ll &count) {
        vis[i][j] = TIME;
        if(grid[i][j]=='9') {
            count++;
            return;
        }
        const vector<vector<int>> dirs = {{0,-1},{-1,0},{0,1},{1,0}};
        for(auto &d: dirs) {
            int ni = i + d[0], nj=j+d[1];
            if(inside(ni,nj,H,W) && vis[ni][nj]!=TIME && grid[ni][nj] == 1+ grid[i][j]) dfs(ni,nj,H,W,grid,vis,count);
        }
}

int main() {
    vector<string> grid;
    string s;
    while(getline(cin,s)) {
        grid.push_back(s);
    }
    const int H = grid.size(), W= grid[0].size();
    vector<vector<int>> vis(H,vector<int>(W,0));
    ll count = 0;
    for(int i=0;i<H;++i) {
        for(int j=0;j<W;++j) {
            if(grid[i][j]=='0') {
                dfs(i,j,H,W,grid,vis,count);
                TIME++;
            }
        }
    }
    cout<<count<<endl;

}