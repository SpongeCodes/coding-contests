#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll A,B=0,C=0;
    char ins[50];
    scanf("%s",ins);
    scanf(" %s",ins);
    scanf(" %lld",&A);
    for(int i=0;i<7;i++) {
        scanf(" %s",ins);
    }
    vector<pair<int,int>> operations;
    vector<int> targets;
    map<int,ll> combo;
    combo[1] = 1;
    combo[2] = 2;
    combo[3] = 3;
    combo[4] = A; 
    combo[5] = B;
    combo[6] = C;
    int x,y;
    while(scanf(" %d,%d", &x,&y) != EOF) {
        scanf(",");
        operations.emplace_back(x,y);
        targets.push_back(x);
        targets.push_back(y);
    }

    auto simulate = [&] (ll _A) -> vector<ll> {
        A = _A;
        combo[4] = A;
        vector<ll> output;
        for(int i = 0; i < operations.size() ; i++) {
            switch(operations[i].first) {
                case 0:
                    A>>=combo[operations[i].second];
                    combo[4]  = A;
                    break;
                
                case 1:
                    B = B ^ operations[i].second;
                    combo[5] = B;
                    break;

                case 2:
                    B = combo[operations[i].second]%8;
                    combo[5] = B;
                    break;

                case 3:
                    if(A!=0) i = operations[i].second-1;
                    break;
                
                case 4:
                    B = B ^ C;
                    combo[5] = B;
                    break;
                
                case 5:
                    //cout<<combo[operations[i].second]%8<<",";
                    output.emplace_back(combo[operations[i].second]%8);
                    break;
                
                case 6:
                    B = A>>combo[operations[i].second];
                    combo[5] = B;
                    break;
                
                case 7:
                    C = A>>combo[operations[i].second];
                    combo[6] = C;
                    break;
            }
            
        }
        return output;
    };
    
    for(ll ob: simulate(108107574778365LL)) {
        cout<<ob<<", ";
    }
    cout<<endl;

    ll pw = 1024;
    vector<ll> candidates;
    for(int i = 0 ; i<1024;++i) {
       candidates.push_back(i);
    }
    for(int k=0;k<= (int) targets.size();++k) {
        vector<ll> newCands;
        int count = 0;
        for(ll _A: candidates) {
            vector<ll> out = simulate(_A);
            bool ok  = true;
            if(k>=out.size() || out[k]!=targets[k] ) {
                    ok = false;
            }

            if(ok) {
                for(int j = 0 ; j < 8 ; ++j) {
                    newCands.push_back(_A+ pw*j);
                }
            }
        }
        candidates = newCands;
        pw*=8;
        sort(candidates.begin(),candidates.end());
        cout<<(int)candidates.size()<<" "<<candidates[0]<<" "<<candidates[(int)candidates.size()-1]<<endl;
    }
    

}