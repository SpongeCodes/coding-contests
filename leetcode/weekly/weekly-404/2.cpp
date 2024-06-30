#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// SAME SOLUTION AS 3 BUT WITH K=2

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int k=2;
        vector<vector<int>> dp(n,vector<int>(k));
        vector<int> prev(k,-1);
        int res = 0;
        for(int i=0;i<n;i++) {
            // for each index
            // 0 -> comes from same parity
            // 1 -> opposite
            int val = nums[i]%k;
            for(int j=0;j<k;j++) {
                dp[i][j] = (prev[(j-val+k)%k] == -1)? 1 : 1+dp[prev[(j-val+k)%k]][j];
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl; 
                res = max(res,dp[i][j]);
            }
            prev[val] = i;
        }
        return res;
    }
};