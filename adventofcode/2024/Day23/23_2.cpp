#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> lan;

void rec(string u, int i,vector<string> clique,map<string,vector<string>> &edges,set<pair<string,string>> &pairs) {
    if(i == edges[u].size()) {
        if(clique.size() > lan.size()) {
            lan = clique;
        }
        return;
    }
    // all neighbours of a should be connected to b
    rec(u,i+1,clique,edges,pairs);

    string v = edges[u][i];
    for(string s: clique) {
        if(!pairs.count({s,v})) return;
    }
    clique.push_back(v);
    rec(u,i+1,clique,edges,pairs);
}

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
    
    for(string a: nodes) {
        rec(a,0,{a},edges,pairs);
    }
    sort(begin(lan),end(lan));
    for(int i = 0; i< lan.size();++i) {
        cout<<lan[i]<<",\n"[i==lan.size()-1];
    }
}