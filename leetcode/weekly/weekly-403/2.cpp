#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        // find rectangle with min x,y and max x,y 1 locations
        int minX=grid.size(),minY=grid[0].size(),maxX=-1,maxY=-1;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1) {
                    minX = min(minX,i);
                    minY = min(minY,j);
                    maxX = max(maxX,i);
                    maxY = max(maxY,j);
                }
            }
        }
        return (1+maxX-minX) * (1+maxY-minY);
    }
};