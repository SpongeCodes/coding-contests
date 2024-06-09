#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        // find maximum element
        int max=0,maxIndex=-1, n=skills.size();
        for(int i = 0; i< n;++i)
        {
            if(skills[i] > max) {
                max = skills[i];
                maxIndex = i;
            }
        }
        
        int curr = 0 ;
        int run=0;
        for(int j=1;j<n;++j) {
            if(skills[curr]>skills[j])
                run++;
            else {
                curr = j;
                run=1;
            }
            if(run==k || curr==maxIndex) break;
        }
        
        return curr;
    }
};