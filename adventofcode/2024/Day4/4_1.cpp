#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    int N = 140;
    vector<string> grid(N);
    for(string &row: grid){
        cin>>row;
        //cout<<row<<endl;
    }
    int M = grid[0].size();
    int res = 0;

    const auto &inside = [&](int i, int j) {
        return i>=0 && i<N && j>=0 && j<M;
    };
    
    const auto &check = [&](int i, int j) {
        for(int drow=-1;drow<=1;drow++) {
            for(int dcol=-1;dcol<=1;dcol++) {
                if(drow==0 && dcol==0) continue;
                int k= 0;
                for(;k<4;k++) {
                    int r2 = i + drow*k;
                    int c2 = j + dcol*k;
                    if(inside(r2,c2) && grid[r2][c2]=="XMAS"[k]) continue;
                    else break;         
                }
                if(k==4) res++;
            }
        }
    };

    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            if(grid[i][j] == 'X') check(i,j);
        }
    }    
    cout<<res<<endl;
    return 0;
}