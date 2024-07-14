#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        // split the array
        sort(begin(h),end(h),greater<int>());
        sort(begin(v),end(v),greater<int>());
        long long hp=0 ,vp=0,res = 0;
        while(hp<m-1 && vp<n-1) {
            if(h[hp] <= v[vp]) {
                res+= v[vp] * (hp+1);
                vp++;
            }
            else {
                res+=h[hp]*(vp+1);
                hp++;
            }
        }
        while(hp<m-1) {
            res+=h[hp]*n;
            hp++;
        }
        while(vp<n-1) {
            res+=v[vp]*m;
            vp++;
        }
        return res;
    }
};