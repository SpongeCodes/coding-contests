#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 16777216;

void f(ll &x) {
    x = (x ^ (x*64)) % MOD;
    x = (x ^ (x/32)) % MOD;
    x = (x ^ (x*2048)) % MOD;
}

int main() {
    ll res = 0;
    vector<ll> nums;
    int num;
    while(scanf("%d",&num)!=EOF) {
        nums.push_back(num);
    }
    map<vector<int>,ll> prices;
    for(auto x: nums) {
        vector<int> v;
        v.push_back(x%10);
        set<vector<int>> s;
        for(int t=1;t<=2000;t++) {
            f(x);
            v.push_back(x%10);
            if(t>=4) {
                vector<int> d;
                for(int i = 0; i<4; ++i) {
                    // get last 4 differences
                    d.push_back(v[t-3+i] - v[t-4+i]);
                }
                if(!s.count(d)) {
                    s.insert(d);
                    prices[d]+=v[t]%10;

                }
            }
        }
    }
    for(auto [changes,total]: prices) {
        res = max(res,total);
    }
    cout<<res<<endl;
}