#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int i=0,j=nums.size()-1;
        int res = 100;
        while(i<j) {
            res=min(res,nums[i]+nums[j]);
            i++;j--;
        }
        return 1.0*res/2;
    }
};