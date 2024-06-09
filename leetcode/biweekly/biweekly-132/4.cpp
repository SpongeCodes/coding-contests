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
// same idea.. dp[i][j] keeps track of subsequence ending at i with at most j differences

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
       // optimized from O(n^2*k) to O(n*k)
       int n = nums.size();
       vector<vector<int>> dp(n,vector<int>(k+1,1));
       unordered_map<int,int> last;
       // dp[i][j] => ending index i at most j different indices
       vector<int> lengths(k+1,0); // maximum lengths 
       // lengths[j] -> maximum length of subsequence with upto j differences
       for(int i=0;i<n;++i) {
            for(int j=k;j>=0;--j) {
                // if you wanted to iterate in other order i.e 0 to k
                // you would have to use previous iterations lengths[j-1] so lengths would be 2D to propagate
                // have to find best result from previous index with k-1 differences
                dp[i][j] = max(dp[i][j], 
                1+(last.find(nums[i])==last.end()? 0:dp[last[nums[i]]][j]) );
                if(j>0) dp[i][j] = max(dp[i][j], 1 + lengths[j-1] ); // this would be lengths[i-1][j-1]
                lengths[j] = max(dp[i][j],lengths[j]); // this would become lengths[i][j] = max(dp[i][j], lengths[i-1][j])
            }
            last[nums[i]] = i;
       }
        return lengths[k];
    }
};