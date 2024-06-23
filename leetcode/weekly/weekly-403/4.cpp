#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
int boundingRect(vector<vector<int>>& grid, int i1,int i2, int j1, int j2) {
    int minX = i2+1, minY=j2+1 , maxX = -1, maxY= -1;
    bool found = 0;
    for(int i=i1;i<=i2;++i) {
        for(int j=j1;j<=j2;++j) {
            if(grid[i][j]==1) {
                found = 1;
                minX = min(minX,i);
                maxX = max(maxX,i);
                minY = min(minY,j);
                maxY=  max(maxY,j);
            }
        }
    }
    // have to handle if nothing is in this range?
    return found? (maxX-minX+1)*(maxY-minY+1):1000;
}

int helper(vector<vector<int>>& grid, int i1,int i2, int j1, int j2) {
    int res = INT_MAX;
    // can divide this part of the grid containing two rectangles
    for (int i = i1; i <= i2; ++i)
        res = min(res, boundingRect(grid,i1,i,j1,j2) + boundingRect(grid,i+1,i2,j1,j2));
    for (int j = j1; j <= j2; ++j)
        res = min(res, boundingRect(grid,i1,i2,j1,j) + boundingRect(grid,i1,i2,j+1,j2));
    return res;
}

public:
    int minimumSum(vector<vector<int>>& grid) {
        // an extension of problem 2
        // note that dividing grid into two regions will separate the 3 rectangles
        // We can choose the horizontal/vertical dividing line
        int res = INT_MAX;
        int n = grid.size(), m =grid[0].size();
        // dividing horizontally
        for(int i=0;i<n;++i) {
            res = min({res,
                       boundingRect(grid,0,i,0,m-1)+helper(grid,i+1,n-1,0,m-1),
                       boundingRect(grid,i+1,n-1,0,m-1)+helper(grid,0,i,0,m-1)});
        }
        // dividing vertically
        for(int j=0;j<m;++j) {
             res = min({res,
                       boundingRect(grid,0,n-1,0,j)+helper(grid,0,n-1,j+1,m-1),
                       boundingRect(grid,0,n-1,j+1,m-1)+helper(grid,0,n-1,0,j)});
        }
        return res;
    }
};