#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// DIFFERENCE BETWEEN PART 1 AND PART 2 is that in part 2 the same '9' cell can be reached via different paths
// and all paths should be counted
// in part 1 only the distinct 9s reached from a trailhead count

bool inside(int i, int j,const int &H, const int &W) {   
        return i>=0 && i<H && j>=0 && j<W;
}

void dfs(int i,int j,const int &H, const int &W, vector<string> &grid,ll &count) {
        if(grid[i][j]=='9') {
            count++;
            return;
        }
        const vector<vector<int>> dirs = {{0,-1},{-1,0},{0,1},{1,0}};
        for(auto &d: dirs) {
            int ni = i + d[0], nj=j+d[1];
            if(inside(ni,nj,H,W) && grid[ni][nj] == 1+ grid[i][j]) dfs(ni,nj,H,W,grid,count);
        }
}

int main() {
    vector<string> grid;
    string s;
    while(getline(cin,s)) {
        grid.push_back(s);
    }
    const int H = grid.size(), W= grid[0].size();
    ll count = 0;
    for(int i=0;i<H;++i) {
        for(int j=0;j<W;++j) {
            if(grid[i][j]=='0') dfs(i,j,H,W,grid,count);
        }
    }
    cout<<count<<endl;

}