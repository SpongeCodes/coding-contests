#include<bits/stdc++.h>
using namespace std;
class Solution {
    long long maximumTotalDamage(vector<int>& power) {
        deque<array<long long, 2>> dp{{0, 0}};
        long long max_dp = 0;
        sort(begin(power), end(power));
        for (int p : power)
            if (p == dp.back()[1])
                dp.back() = {p + dp.back()[0], p};
            else {
                while(!dp.empty() && dp.front()[1] + 2 < p) {
                    max_dp = max(max_dp, dp.front()[0]);
                    dp.pop_front();
                }
                dp.push_back({p + max_dp, p});
            }
        return (*max_element(begin(dp), end(dp)))[0];
    }
};

// MY SOLUTION with indices same logic with deque
using ll = long long;
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // YOU NEED DP
       int n = power.size();
       ll max_dp=0;
       deque<pair<int,ll>> dq;
       sort(power.begin(),power.end());
       dq.push_back({0,power[0]});
       // YOU CAN USE 2 POINTERS
       // NOW OPTIMIZED SOLUTION IS TO USE DEQUEUE
       for (int i = 1; i < power.size(); ++i) {
            if(power[i]==power[dq.back().first]) {
                ll newVal = dq.back().second + power[i];
                dq.back() = {i,newVal};
            }
            // else go get max_dp upto i-2
            else {
                while(!dq.empty() && power[dq.front().first]+2<power[i]) {
                    max_dp = max(max_dp,dq.front().second);
                    dq.pop_front();
                }
                dq.push_back({i,max_dp+power[i]});
            }
       }
       while(!dq.empty()) {
            max_dp = max(max_dp,dq.front().second);
            dq.pop_front();
       } 
       return max_dp;
    }
};
// ---------------------
// O(N) memory maintaining entire dp array
using ll = long long;
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // YOU NEED DP
       int n = power.size();
       ll max_dp=0;
       long long dp[n];
       sort(power.begin(),power.end());
       dp[0] = power[0];
       // YOU CAN USE 2 POINTERS
       for (int i = 1, j = 0; i < power.size(); ++i) {
            if(power[i]==power[i-1]) dp[i] = power[i]+dp[i-1];
            // else go get max_dp upto i-2
            else {
                while(power[j]+2<power[i]) {
                    max_dp = max(max_dp,dp[j++]);
                }
                dp[i] = power[i] + max_dp;
            }
       } 
       return *max_element(dp, dp+n);
    }
};

/**
 * PYTHON SOLUTION TAKE/NOT TAKE WILL NOT PASS IN CPP -CREDIT QIQI_IMPACT
class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        power.sort()
        @cache
        def dp(idx, lst):
            if idx == len(power):
                return 0
            v = power[idx]
            ret = dp(idx+1, max(lst, v - 3))
            if v - lst not in [1, 2]:
                ret = max(ret, v + dp(idx+1, v))
            return ret
        return dp(0, -inf)
        
*/