#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
       // optimized from O(n^2*k) to O(n*k)
       int n = nums.size();
       vector<unordered_map<int,int>> dp(k+1);
       vector<int> lengths(k+1,0); // maximum lengths 
       // lengths[j] -> maximum length of subsequence with upto j differences
       for(int i=0;i<n;++i) {
            for(int k1 = k; k1>=0;--k1) {
                // this will insert nums[i] into map
                dp[k1][nums[i]] = max(dp[k1][nums[i]]+1,(k1>0? lengths[k1-1]+1:0));
                lengths[k1] = max(lengths[k1],dp[k1][nums[i]]);
            }
       }

       return lengths[k];
    }
};