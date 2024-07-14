#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
 3 solutions
 1. 4D -DP
 2. 2D- DP also possible
 3. Best solution is greedy -  take the maximum between present
    vertical and horizontal cut to minimize the increase of the next opposite cuts
*/

// SOLUTION 1 - WILL FAIL FOR HIGHER CONSTRAINTS
class Solution {
private:
long long f(int l1,int l2, int r1, int r2, vector<int> &h, vector<int>&v,
    int dp[][21][21][21]) {
    if (l2-l1==1 && r2-r1==1) return 0;
    if(dp[l1][l2][r1][r2] != -1) return dp[l1][l2][r1][r2];
    long long res= INT_MAX;
    for(int i= l1+1;i<l2;i++) {
        res = min(res,h[i-1] + f(l1,i,r1,r2,h,v,dp) + f(i,l2,r1,r2,h,v,dp));
    }
    for(int j= r1+1;j<r2;j++) {
        res = min(res,v[j-1] + f(l1,l2,r1,j,h,v,dp) + f(l1,l2,j,r2,h,v,dp));
    }
    return dp[l1][l2][r1][r2] = res;
}
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int dp[21][21][21][21];
        memset(dp,-1,sizeof(dp));
        return f(0,m,0,n,horizontalCut,verticalCut,dp);
    }
};

// SOLUTION 3 GREEDY
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