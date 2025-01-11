#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<pair<int,int>> v;
    int x,y, H=71,W=71;
    vector<string> grid(H,string(W,'.'));
    while(scanf("%d, %d",&x,&y) !=EOF) {
        v.emplace_back(y,x);
    }
    
    for(int i=0;i<1024;++i) {
        grid[v[i].first][v[i].second] = '#';
    }

    queue<pair<int,int>> q;
    vector<pair<int,int>> dirs = {{0,-1},{-1,0},{0,1},{1,0}};
    
    auto valid = [&](int x, int y) {
        return x>=0 && x<H && y>=0 && y<W && grid[x][y] != '#';
    };

    q.push({0,0});
    vector<vector<int>> time(H,vector<int>(W,-1));
    time[0][0] = 0;
    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        int cx = top.first, cy = top.second;
        if(cx==H-1 && cy==W-1) {
            break;
        }
        for(auto &d: dirs) {
            int nx = cx+d.first, ny = cy+d.second;
            if(valid(nx,ny) && time[nx][ny]==-1) {
                time[nx][ny] = 1+time[cx][cy];
                q.push({nx,ny});
            }
        }

    }
    cout<<time[H-1][W-1]<<endl;
    return 0;
}