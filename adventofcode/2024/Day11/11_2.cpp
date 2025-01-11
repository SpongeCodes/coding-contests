#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    string line;
    ll res=0;
    map<ll,ll> m;
    int tmp;
    while(scanf("%d",&tmp) != EOF) {
        m[tmp]++;
    }
    for(int k=0;k<75;++k) {
        map<ll,ll> new_m;
        for(auto &[v,cnt]: m) {
            if(v==0) {
                new_m[1]+=cnt;
            }
            else if(to_string(v).size() % 2 == 0) {
                int len = (int) to_string(v).size();
                new_m[stoll(to_string(v).substr(0,len/2))] += cnt;
                new_m[stoll(to_string(v).substr(len/2))] += cnt;
            }
            else {
               new_m[2024*v] += cnt;
            }
        }
        m = new_m;
    }
    for(auto &[_,cnt]: m) {
        res += cnt;
    }
    cout<<res<<endl;
    return 0;
}