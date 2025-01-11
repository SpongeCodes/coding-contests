#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    char s[5];
    map<string,vector<string>> edges;
    set<pair<string,string>> pairs;
    set<string> nodes;

    while(scanf("%s",s) != EOF) {
        string a(s,s+2);
        string b(s+3,s+5);
        nodes.insert(a);
        nodes.insert(b);
        edges[a].push_back(b);
        edges[b].push_back(a);
        pairs.insert({a,b});
        pairs.insert({b,a});
    }
    ll res = 0;
    for(string a: nodes) {
        for(string b: edges[a]) {
            for(string c: edges[b]) {
                if(pairs.count({a,c})) {
                    if(a[0] == 't' || b[0]=='t' || c[0]=='t') res++;
                }
            }
        }
    }
    res/=6;
    cout<<res<<endl;
}