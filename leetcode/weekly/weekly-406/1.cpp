#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    string getSmallestString(string s) {
        for(int i=0;i<s.size()-1;i++) {
            if(s[i]%2 == s[i+1]%2) {
                if(s[i] > s[i+1]) {
                    swap(s[i],s[i+1]);
                    break;
                }
            }
        }
        return s;
    }
};