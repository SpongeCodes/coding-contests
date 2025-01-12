#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ll res = 0;
    string s;
    cin>>s;
    int n = s.size(), id=0, pos=0;
    vector<int> p;
    for(int i=0;i<n;++i) {
        if(i%2==0) {
            for(int j=0;j<s[i]-'0';j++) p.emplace_back(id);
            id++;
        }
        else {
            for(int j=0;j<s[i]-'0';j++) p.emplace_back(-1);
        }
        pos+=s[i]-'0';
    }
    n = p.size();
    int i=0,j=n-1;
    while(true) {
        while(i<j && p[i]!= -1) i++;
        while(i<j && p[j]==-1) j--;
        while(i<j && p[i]==-1 && p[j]!=-1) {
            p[i]=p[j];
            p[j]=-1;
            i++;j--;
        }
        if(i>=j) break;
    }
    for(int i=0;p[i]!=-1;i++) {
        res+= 1ll*i*p[i];
    }
    cout<<res<<endl;
    return 0;
}