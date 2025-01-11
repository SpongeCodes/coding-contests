#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void f(int i,int n,ll curr, ll target,vector<ll>&nums, bool &isOk) {
    if(i==n) {
        if(curr == target) isOk = true;
        return;
    }
    f(i+1,n,curr+nums[i],target,nums,isOk);
    f(i+1,n,curr*nums[i],target,nums,isOk);
}

int main() {
    string line;
    ll res=0;
    while(getline(cin,line)) {
        int sz = line.size();
        ll curr = 0;
        int i;
        for(i=0;line[i]!=':';++i) {
            curr = curr*10 + (line[i]-'0');
        }
        i++;
        vector<ll> nums;
        while(true) {
            while(i<sz && line[i]==' ') i++;
            if(i==sz) break;
            ll curr=0;
            while(i<sz && line[i]>='0' && line[i]<='9') {
                curr = curr*10 + (line[i]-'0');
                i++;
            }
            nums.push_back(curr);
        }
        bool ok = false;
        f(1,nums.size(),nums[0],curr,nums,ok);
        if(ok) res+=curr;
    }
    cout<<res<<endl;
   
    return 0;
}