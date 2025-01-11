#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    char grid[51][51];
    int W = -1, H = 0;
    vector<pair<int,int>> where[256];
    for(int row=0; scanf(" %s",grid[row]) != EOF; H++,row++) {
        W = strlen(grid[row]);
        //cout<<W<<endl;
        for(int col = 0; col < W ; ++col) {
            if(grid[row][col] != '.') {
                where[(int)grid[row][col]].emplace_back(row,col);
            }
        }
    }
    vector<vector<bool>> antinodes(H,vector<bool>(W,0));
    int res = 0;
    for(int k=0;k<256;++k) {
        const vector<pair<int,int>> &v = where[k];
        for(int i=0;i<v.size();++i) {
            for(int j=0;j<v.size();++j) {
                if(i==j) continue;
                int r1 = v[i].first, c1 = v[i].second;
                int r2 = v[j].first, c2 = v[j].second;
                int dr = (r2-r1);
                int dc = (c2-c1);
                int gcd = __gcd(abs(dr),abs(dc));
                dr/=gcd;
                dc/=gcd;
                int count = 0;
                for(int m=-min(H,W); m<=min(H,W); ++m) {
                    //if(m==0) continue;
                    int r = r1 + m*dr, c = c1 + m*dc;
                    //if(r==r2 && c==c2) continue;
                    if(0<=r && r<H && 0<=c && c<W) {
                        count++;
                        if(!antinodes[r][c] ) {
                            antinodes[r][c] = true;
                            res++;
                        }
                    }
                }
                 
            }
        }
    }

    cout<<res<<endl;
    return 0;
}