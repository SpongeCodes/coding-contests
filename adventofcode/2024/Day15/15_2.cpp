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
                grid[i][j]= '.';
            }
        }
    }
    me.second *=2 ;
    int next_id = 1;
    vector<string> newGrid(H,string(2*W,' '));
    vector<vector<int>> id(H,vector<int>(2*W));
    for(int i=0;i<H;++i) {
        for(int j=2*W-1;j>=0;--j) {
            newGrid[i][j] = grid[i][j/2];
            if(grid[i][j/2]=='O') {
                id[i][j]  = next_id;
                if(j%2==0) {
                    next_id++;
                }
            }
        }
    }
    for(char c: moves) {
        pair<int,int> dir = getDir(c);
        vector<pair<int,int>> boxes;
        set<int> vis;
        boxes.push_back(me);
        bool blocked = false;
        for(int i=0;i<boxes.size();i++) {
            int row = boxes[i].first  + dir.first;
            int col = boxes[i].second + dir.second;
            if(newGrid[row][col] == '#') {
                blocked = true;
                break;
            }
           
            if(newGrid[row][col] == 'O') {
                if(!vis.count(id[row][col])) {
                    boxes.emplace_back(row,col);
                    vis.insert(id[row][col]);
                     // to account for double size of boxes
                    for(int c: {col-1,col+1}) {
                        if(id[row][c] == id[row][col]) {
                            boxes.emplace_back(row,c);
                        }
                    }
                }
            }
        
        }
        if(blocked) continue;
        me.first += dir.first;
        me.second += dir.second;
        boxes.erase(boxes.begin());
        vector<vector<int>> tmp(H,vector<int>(2*W));
        for(pair<int,int> b: boxes) {
            newGrid[b.first][b.second] = '.';
            tmp[b.first][b.second] = id[b.first][b.second];
            id[b.first][b.second] =  0;
        }
        for(pair<int,int> b: boxes) {
            newGrid[b.first + dir.first][b.second+dir.second] = 'O';
            id[b.first + dir.first][b.second + dir.second] = tmp[b.first][b.second]; 
        }   
    }
    ll res = 0;
    for(int i=0;i<H;++i) {
        for(int j=0;j<2*W;++j) {
            // count each box only once
            if(newGrid[i][j]=='O' && (j==0 || j>1 &&  id[i][j]!=id[i][j-1])) res += 100*i+j;
        }
    }
    cout<<res<<endl;
    
    return 0;
}