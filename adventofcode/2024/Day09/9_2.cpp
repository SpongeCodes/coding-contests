#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Block{
    int id, size,pos;
};

int main() {
    ll res = 0;
    string s;
    cin>>s;
    int n = s.size(), pos=0;
    vector<Block> blocks;
    for(int i=0;i<n;++i) {
        if(i%2==0) {
            blocks.push_back(Block{i/2,s[i]-'0',pos});
        }
        pos+=s[i]-'0';
    }
    while(blocks.size() > 1) {
        Block me = blocks.back();
        bool inserted = false;
        for(int i=0;i<(int)blocks.size()-1;++i) {
            int A = blocks[i].pos + blocks[i].size;
            int B= blocks[i+1].pos;
            if(B-A>=me.size) {
                inserted = true;
                blocks.pop_back();
                me.pos = A;
                blocks.insert(blocks.begin()+i+1,me);
                break;
            }
            
        }
        if(!inserted) {
            blocks.pop_back();
            for(int j=0; j<me.size;j++)
                res += (me.pos+j)*me.id;
        }
    }
    cout<<res<<endl;
    return 0;
}