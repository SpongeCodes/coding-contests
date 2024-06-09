#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        // dp[j][k] length of longest subsequence ending at j with at most k unequals
        for(int i=0;i<n;++i) dp[i][0]= 1;
        int res = 1;
        for(int i=0;i<n;i++){
               for(int j=0;j<i;++j) {
                   for(int k1=0;k1<=k;k1++) {
                        int k2 = k1 - (nums[j] !=nums[i]);
                        if(k2>=0) dp[i][k1] = max(dp[i][k1],1+dp[j][k2]);
                        res = max(dp[i][k1],res);
                   }
               }
        }
        return res;
    }
};