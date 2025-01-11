#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<string> grid;
    string s;
    while(getline(cin,s)) {
        grid.push_back(s);
    }
    int N = grid.size(), M = grid[0].size();
    int st_x = -1, st_y = -1;
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            if(grid[i][j]=='^') {
                st_x= i, st_y = j;
            }
        }
    } 
    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    // PART 2 
    // A loop will occur if same index with same direction is seen
    const auto good = [&]() {
        set<pair<int,int>> visitedWithDir;
        int x = st_x, y= st_y, d=0;;
        while(0<=x && x<N && 0<=y && y<M) {
            if(visitedWithDir.count({x*M+y,d}))  return true;
            visitedWithDir.insert({x*M+y,d});
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(nx>=0 && nx<N && ny>=0 && ny<M) {
                if(grid[nx][ny] == '#') {
                    d = (d+1)%4;
                    continue;
                }
            }
            x=nx;
            y=ny;
        }
        return false;    
    };
    int res = 0;
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            if(grid[i][j]=='.') {
                grid[i][j] = '#';
                if(good()) res++;
                grid[i][j] = '.';
            }
        }
    }
    cout<<res<<endl;
    return 0;
}