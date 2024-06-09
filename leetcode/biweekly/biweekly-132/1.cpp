#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string clearDigits(string s) {
        vector<int> notDigitPos;
        int n  = s.size();
        string newString = "";
        for(int i=0;i<n;i++) {
            char c = s[i];
            if(c>='0' && c<='9') {
                if(notDigitPos.size() > 0) notDigitPos.pop_back();
            }
            else notDigitPos.push_back(i);
        }
        for(int i: notDigitPos) newString+=s[i];
        return newString;
    }
};