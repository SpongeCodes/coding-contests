#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    int maximumLength(vector<int>& nums,int k) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(k));
        // dp[i][j] -> length of longest subsequence upto index i with pairwise sum j
        vector<int> prev(k,-1);
        int res = 0;
        for(int i=0;i<n;i++) {
            int val = nums[i]%k;
            for(int j=0;j<k;j++) {
                // find prev, if no such prev exists it can be taken as start i.e 1 length
                dp[i][j] = (prev[(j-val+k)%k] == -1)? 1 : 1+dp[prev[(j-val+k)%k]][j];
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl; 
                res = max(res,dp[i][j]);
            }
            prev[val] = i;
        }
        return res;
    }
};

// A BETTER SPACE COMPLEXITY SOLUTION WITH FIXING THE sum of first and second elements of subsequence
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        const int n = nums.size();
        assert(n >= 1 && n <= 1000 && k >= 1 && k <= 1000);
        vector<int> c(k);
        int r = 0;
        for (int i = 0; i < n; ++i) {
            assert(nums[i] >= 0 && nums[i] <= 10000000);
            const int x = nums[i] % k;
            r = max(r, ++c[x]);
            if (c[x] > 1) continue;
            vector<int> last(k, -1), len(k);
            last[x] = i;
            for (int j = i + 1; j < n; ++j) {
                const int y = nums[j] % k;
                if (x == y) {
                    last[x] = j;
                    continue;
                }
                if (last[y] < last[x]) {
                    len[y] += 2;
                    last[y] = j;
                }
            }
            for (int j = 0; j < k; ++j) {
                if (j != x && last[j] >= 0) {
                    r = max(r, len[j] + (last[x] > last[j]));
                }
            }
        }

        return r;
    }
};