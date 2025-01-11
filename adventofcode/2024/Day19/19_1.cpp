#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    vector<string> pats;
    while(true) {
        char s[20];
        scanf("%s",s);
        pats.push_back(s);
        if(pats.back().back() == ',') pats.back().pop_back();
        else break;
    }
    ll res = 0;
    string s;
    while(getline(cin,s)) {
        if(s == "\n" || s.size() == 0) continue;
        const int N = s.size();
        vector<bool> dp(N+1,false);
        dp[0] = true;
        for(int i=0;i<N;++i) {
            if(dp[i]) {
                for(string p: pats) {
                    bool f = true;
                    int len = p.size();
                    for(int j=0; j < len; ++j) {
                        if(i+j >= N || s[i+j] != p[j]) {
                            f = false;
                            break;
                        }
                    }
                    if(f) dp[i+len] = true;
                }
            }
        }
        res += dp[N];
    }

    cout<<res<<endl;
    return 0;
}