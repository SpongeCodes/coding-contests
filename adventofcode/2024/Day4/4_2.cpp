#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int N = 140;
    vector<string> grid(N);
    for(string &row: grid){
        cin>>row;
    }
    int M = grid[0].size();

    const auto &inside = [&](int i, int j) {
        return i>=0 && i<N && j>=0 && j<M;
    };
    
    const auto &check = [&](int i, int j) {
            int cnt = 0;
            if(inside(i-1,j-1) && grid[i-1][j-1]=='M' && inside(i+1,j+1) && grid[i+1][j+1]=='S') cnt++;
            if(inside(i-1,j-1) && grid[i-1][j-1]=='S' && inside(i+1,j+1) && grid[i+1][j+1]=='M') cnt++;
            if(inside(i-1,j+1) && grid[i-1][j+1]=='M' && inside(i+1,j-1) && grid[i+1][j-1]=='S') cnt++;
            if(inside(i-1,j+1) && grid[i-1][j+1]=='S' && inside(i+1,j-1) && grid[i+1][j-1]=='M') cnt++;
            return cnt==2;
    
    };

    int res = 0;
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            if(grid[i][j] == 'A' && check(i,j)) res++;
        }
    }    
    cout<<res<<endl;
    return 0;
}