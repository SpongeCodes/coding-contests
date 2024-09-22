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

// LESS EFFICIENT SOLUTION MAINTAINING ALL INDEXES OF 26 CHARACTERS WITH O(26) CHECK
// WILL GIVE MLE/TLE FOR Q4 with higher constraints
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        // if a substring contains word2 letters it can be rearranged
        // we just need to maintain frequency count using sliding window
        vector<int> freq2(26);
        vector<int> minInd(26,1e6);
        vector<vector<int>> cnt(26);
        long long res = 0;
        for(char c: word2) {
            freq2[c-'a']++;
            minInd[c-'a'] = -1;
        }
        for(int i=0;i<word1.size();++i) {
            char c = word1[i];
            if(freq2[c-'a'] > 0) {
                cnt[c-'a'].push_back(i);
                if(cnt[c-'a'].size()>=freq2[c-'a']) 
                    minInd[c-'a'] = cnt[c-'a'][(int)cnt[c-'a'].size()-freq2[c-'a']];
            }
            // find minimum of val
            int mini=1e6;
            for(auto &x: minInd) {
                mini = min(mini,x);
            }
            if(mini>-1) res+=(mini+1); 
        }
        return res;
    }
};