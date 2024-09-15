#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        const long long MIN = -1e11;
        vector<long long> res(4,MIN);
        for(long long i: b) {
            res[3] = max(res[3],res[2]+a[3]*i);
            res[2] = max(res[2],res[1]+a[2]*i);
            res[1] = max(res[1],res[0]+a[1]*i);
            res[0] = max(res[0],a[0]*i);
        }
        return res[3];
    }
};