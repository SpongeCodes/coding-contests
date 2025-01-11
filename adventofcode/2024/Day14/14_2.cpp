#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int px,py,vx,vy;
    int H = 103, W=101, T=100;
    vector<pair<int,int>> p, vel;
    while(scanf(" p=%d,%d v=%d,%d",&px,&py,&vx,&vy) == 4) {
        //cout<<px<<" "<<py<<" "<<vx<<" "<<vy<<endl;
        p.emplace_back(px,py);
        vel.emplace_back(vx,vy);
    }   
    vector<string> grid(H,string(W,' '));
    int len = (int) p.size();
    int turns = 0;
    while(true) {
        turns++;
        for(int i=0;i<len;++i) {
            int &x = p[i].first;
            int &y = p[i].second;
            grid[y][x] = ' ';
            x += vel[i].first;
            y += vel[i].second;
            x = (x%W+W)%W;
            y = (y%H+H)%H;
            grid[y][x] = '#';
        }
        int cnt = 0;
        for(int i=0;i<H;++i) {
            for(int j=0;j<W;j++) {
                if(j < W-1-j && grid[i][j] == '#' && grid[i][j] == grid[i][W-1-j]) {
                    cnt++;
                }
            }
        }

        if(cnt>=50) {
            cout<<turns<<endl;
            for(int i=0;i<H;++i) {
                cout<<grid[i].c_str()<<endl;
            }
        }
    }

    return 0;
}