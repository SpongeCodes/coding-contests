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