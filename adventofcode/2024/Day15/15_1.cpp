#include<bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int,int> getDir(char ch) {
        switch(ch) {
            case '^': return {-1,0};
            case '>': return {0,1};
            case 'v': return {1,0};
            case '<': return {0,-1};
            
        }
        assert(false);
        return {0,0};
}

int main() {
    vector<string> grid;
    string moves;
    string row;
    int H,W;
    
      /*alternate way to take input
      for(int row = 0; true;row++) {
            char s[1001];
            fgets(s,sizeof(s),stdin);
            s[strcspn(s, "\n")] = '\0';
            W = strlen(s);
            if(W == 0 || (row>=1 && grid[row-1].size() != W)) {
                H = row;
                W = grid[row-1].size();
                while(fgets(s,sizeof(s),stdin) != NULL) moves+=string(s);
                break;
            }      
            grid.push_back(s);
      }
      */
    while(getline(cin,row)) {
        if(row.size() == 0) break;
        grid.push_back(row);
    }
    while(getline(cin,row)) {
        moves += row;
    }
    H = grid.size(), W=grid[0].size();
    // cout<<H<<" "<<W<<endl;
    // cout<<moves<<endl;
    pair<int,int> me;
    for(int i=0;i<H;++i) {
        for(int j=0; j<W;++j) {
            if(grid[i][j] == '@') {
                me = {i,j};
                grid[i][j] = '.';
            }
        }
    }

    for(char c: moves) {
        pair<int,int> dir = getDir(c);
        vector<pair<int,int>> boxes;
        int row = me.first, col = me.second;
        bool emptySpace = false;
        while(true) {
            row+=dir.first;
            col+=dir.second;
            if(grid[row][col]=='#') {
                break;
            }
            if(grid[row][col] == '.') {
                emptySpace = true;
                break;
            }
            assert(grid[row][col]=='O');
            boxes.emplace_back(row,col);
        }
        if(!emptySpace) continue;
        me.first += dir.first;
        me.second += dir.second;
        for(pair<int,int> b: boxes) {
            grid[b.first][b.second] = '.';
        }
        for(pair<int,int> b: boxes) {
            grid[b.first + dir.first][b.second+dir.second] = 'O';
        }   
    }
    ll res = 0;
    for(int i=0;i<H;++i) {
        for(int j=0;j<W;++j) {
            if(grid[i][j]=='O') res += 100*i+j;
        }
    }
    cout<<res<<endl;
    
    return 0;
}