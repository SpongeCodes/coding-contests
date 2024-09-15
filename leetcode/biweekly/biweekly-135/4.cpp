#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    ll maximumScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<ll>> pref(n+1,vector<ll>(m,0));
        vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>>(n + 1, vector<ll>(2, 0)));
        for(int j=0;j<m;j++) {
            for(int i=1;i<=n;i++)
                pref[i][j] = pref[i-1][j] + grid[i-1][j];
        }


        // 3D DP
        // dp[i][prevDepth][isBigger]
        // isBigger tells if current column is taken as the adjacent for i-1
        for (int i = m-1; i >= 1; --i) {
            for (int isBigger = 0; isBigger < 2; ++isBigger) {
                for (int prevBlack = 0; prevBlack <= n; ++prevBlack) {
                    // iterate over current depth
                    for (int currBlack = 0; currBlack <= n; currBlack++) {
                        ll currentIsBigger = max(0LL,pref[currBlack][i-1] - pref[prevBlack][i-1]);
                        ll nextNotBigger = max(0LL,pref[prevBlack][i] - pref[currBlack][i]);
                        ll takeCurrent = (isBigger)? currentIsBigger:0;
                        // if isBigger can take or not take and move to next
                        // if not isBigger can only notTake
                        ll canTakeNext = takeCurrent + max(dp[i+1][currBlack][0],dp[i+1][currBlack][1]);
                        ll cannotTakeNext = takeCurrent + nextNotBigger + dp[i+1][currBlack][0];
                        ll res = max(canTakeNext,cannotTakeNext);
                        dp[i][prevBlack][isBigger] = max(dp[i][prevBlack][isBigger]
                                                            ,res) ;
                        
                    }
                }
            }
        }
        ll ans = 0;
        for(int i=0;i<=n;++i) {
            ans = max(ans,dp[1][i][1]);
        }
        return ans;
    }
};


// FASTER SOLUTION TO STUDY
