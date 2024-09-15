#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int> m;
        vector<int> res;
        for(int i: nums) {
            m[i]++;
            if(m[i]==2) res.push_back(i);
        }
        return res;
    }
};