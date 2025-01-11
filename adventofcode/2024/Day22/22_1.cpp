#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 16777216;

int main() {
    ll res = 0;
    vector<ll> nums;
    int num;
    while(scanf("%d",&num)!=EOF) {
        nums.push_back(num);
    }
    for(auto x: nums) {
        for(int t=1;t<=2000;t++) {
            x = (x ^ (x*64)) % MOD;
            x = (x ^ (x/32)) % MOD;
            x = (x ^ (x*2048)) % MOD;
        }
        res+=x;
    }
    cout<<res<<endl;
}