#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        // maintain maximum where last is positive/negative
        long long maxLastPos = nums[0], maxLastNeg = INT_MIN;
        for(int i=1;i<n;++i) {
            long long newMaxLastPos = max(maxLastPos,maxLastNeg) + nums[i];
            long long newMaxLastNeg = maxLastPos - nums[i];
            maxLastPos = newMaxLastPos;
            maxLastNeg = newMaxLastNeg;
        }
        return max(maxLastPos,maxLastNeg);
    }
};