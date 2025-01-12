#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    char grid[51][51];
    int W = -1, H = 0;
    vector<pair<int,int>> where[256];
    for(int row=0; scanf("%s",grid[row]) != EOF; H++,row++) {
        W = strlen(grid[row]);
        cout<<W<<endl;
        for(int col = 0; col < W ; ++col) {
            if(grid[row][col] != '.' && grid[row][col]!='#') {
                where[(int)grid[row][col]].emplace_back(row,col);
            }
        }
    }
    //return 0;
    vector<vector<bool>> antinodes(H,vector<bool>(W,0));
    int res = 0;
    for(int k=0;k<256;++k) {
        const vector<pair<int,int>> &v = where[k];
        for(int i=0;i<v.size();++i) {
            for(int j=0;j<v.size();++j) {
                if(i==j) continue;
                int r1 = v[i].first, c1 = v[i].second;
                int r2 = v[j].first, c2 = v[j].second;
                int row = r2 + (r2-r1);
                int col = c2 + (c2-c1);
                
                if(row>=0 && row < H && col>=0 && col<W && !antinodes[row][col]) {
                    antinodes[row][col] = true;
                    res++;
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}