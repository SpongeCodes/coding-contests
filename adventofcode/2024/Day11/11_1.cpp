#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    string line;
    ll res=0;
    vector<ll> nums;
    int tmp;
    while(scanf("%d",&tmp) != EOF) {
        nums.push_back(tmp);
    }
    for(int k=0;k<25;++k) {
        int l = nums.size();
        for(int i=0;i<l;++i) {
            if(nums[i]==0) {
                nums[i] = 1;
            }
            else if(to_string(nums[i]).size() % 2 == 0) {
                int len = (int) to_string(nums[i]).size();
                nums.push_back(stoll(to_string(nums[i]).substr(len/2)));
                nums[i] = stoll(to_string(nums[i]).substr(0,len/2));
            }
            else {
                nums[i] = nums[i]*2024;
            }

        }
    }
    cout<<nums.size()<<endl;
   
    return 0;
}