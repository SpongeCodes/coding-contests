#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        using ll = long long;
        int n = word1.size();
        // if a substring contains word2 letters it can be rearranged
        // we just need to maintain frequency count using sliding window
        // more efficient 
        // can also use a set of the characters required to make the sliding window easier
        // but this is more memory efficient
        array<int,26> cnt;
        ll res = 0;
        int reqLetters = 0;
        for(char c: word2) {
            cnt[c-'a']++;
        }
        for(auto &x: cnt) reqLetters+=(x>0);
        for(ll l =0,r=0;r<n;++r) {
            if(--cnt[word1[r]-'a'] == 0) {
                reqLetters--;
            }
            while(reqLetters==0) {
                if(cnt[word1[l]-'a'] == 0) {
                    res+= l+1;
                    break;
                }
                ++cnt[word1[l++]-'a'];
            }
        }

        return res;
    }
};