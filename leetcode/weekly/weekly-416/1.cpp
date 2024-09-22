#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> ban = set<string>(begin(bannedWords),end(bannedWords));
        int spam = 0;
        for(auto &s: message) {
            if(ban.count(s)==1) spam++;
            if(spam==2) return true; 
        }
        return false;
    }
};