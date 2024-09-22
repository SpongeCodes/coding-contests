#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// SOLUTION 1 C++ NESTED BINARY SEARCH
class Solution {
private:
long long workerCanTake(int w,long long m) {
    long long l = 0, r = sqrt(2*m/w)+1;
    // find most work that can be done within time
    while(l<r) {
        long long mid = l + ((r-l+1)>>1);
        if(mid*(mid+1)*w > 2*m) r = mid-1;
        else l = mid;
    }
    return l;
}
bool can(long long m,int mountainHeight,vector<int> &wt) {
    long long res = 0;
    for(auto &w: wt) {
        res+=workerCanTake(w,m);
    }
    return res>=mountainHeight;
}

public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        sort(begin(workerTimes),end(workerTimes));
        // assign more height to the smaller workerTimes
        long long l = 1, r = (long long)mountainHeight*(mountainHeight+1)/2 * workerTimes[0];
        // binary search
        while(l<r) {
            long long m = l + ((r-l)>>1);
            if(can(m,mountainHeight,workerTimes)) 
                r=m;
            else l = m+1;
        }
        return r;
    }
};