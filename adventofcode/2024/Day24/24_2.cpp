#include<bits/stdc++.h>
using namespace std;
using ll = long long;

map<string,int> nameID;
int N = 1;
int getID(string s) {
    if(nameID.count(s)) {
        return nameID[s];
    }
    nameID[s] = N++;
    return nameID[s];
}

string getString(int ID) {
    for(auto &p: nameID) {
        if(p.second == ID) return p.first;
    }
    return NULL; 
}

const int XOR = 0, OR = 1 , AND = 2 ;

int getOP(string s) {
    if(s == "XOR") return XOR;
    if(s == "OR") return OR;
    if(s == "AND") return AND;
    assert(false);
}

struct Operation {
    int a,b,c;
    int op;
};

int main() {
    string s;
    while(true){
        getline(cin,s);
        if(s.empty()) break;
    }
    vector<int> xs,ys,zs;
    string tmp = "xyz";
    for(char c: tmp) {
        for(int i = 0; i<=45;++i) {
            string s;
            s+=c;
            if(i<10) s+="0";
            s+=to_string(i);
            if(c=='x') xs.push_back(getID(s));
            if(c=='y') ys.push_back(getID(s));
            if(c=='z') zs.push_back(getID(s));
        }
    }  
    vector<Operation> ops;
    char a[5],b[5],c[5], out[5];
    while(scanf(" %s", a) != EOF) {
        scanf(" %s  %s -> %s",out,b,c);
        //printf("%s %s %s %s \n",a,out,b,c);
        int A = getID(string(a));
        int B = getID(string(b));
        int C = getID(string(c));
        ops.push_back(Operation{A,B,C,getOP(string(out))});
    }
    auto simulate = [&](ll x, ll y) {
        vector<int> value(N,-1);
        for(int i= 0 ; i<45; ++i) {
            value[xs[i]] = bool(x & (1LL<<i));
            value[ys[i]] = bool(y & (1LL<<i));
        }
        while(true) {
            bool anything = false;
            for(Operation o: ops) {
                if(value[o.a] != -1 && value[o.b] != -1 && value[o.c] == -1) {
                    int x1 = value[o.a], y1 = value[o.b];
                    int ot =  o.op;
                    value[o.c] = (ot==XOR)? x1^y1: (ot==OR ? x1|y1 : x1&y1);
                    anything = true;
                }
            }
            if(!anything) {
                break;
            }
        }
        ll answer = 0;
        int i = 0;
        for(int id: zs) {
            if(value[id] == -1) return 0ll;
            answer += ((ll)value[id]) << i;
            i++;
        }
        return answer;
    };
    
    // for(int i = 0 ; i<44 ; ++i) {
    //     ll j = 1LL<<i;
    //     //cout<<j<<endl;
    //     if(simulate(j,j) != 2*j) {
    //         cout<<i<<" ";
    //     }
    // }
    // 4 10 11 24 34 35
    //swap(ops[23].c,ops[132].c);
    //swap(ops[55].c ,ops[132].c);
    //swap(ops[23].c,ops[176].c);
    //swap(ops[8].c,ops[58].c);
    swap(ops[132].c,ops[176].c);
    //swap(ops[41].c,ops[134].c);
    //swap(ops[25].c,ops[41].c);
    swap(ops[134].c,ops[145].c);
    swap(ops[88].c,ops[166].c);
    //swap(ops[103].c,ops[114].c);
    swap(ops[114].c,ops[201].c);
    //swap(ops[114].c,ops[207].c);
    vector<string> swaps;
    swaps.push_back(getString(ops[132].c));
    swaps.push_back(getString(ops[176].c));
    swaps.push_back(getString(ops[134].c));
    swaps.push_back(getString(ops[145].c));
    swaps.push_back(getString(ops[88].c));
    swaps.push_back(getString(ops[166].c));
    swaps.push_back(getString(ops[114].c));
    swaps.push_back(getString(ops[201].c));
    sort(begin(swaps),end(swaps));
    //swap(ops[25].c,ops[26].c);
    // see for which prefix a swap causes the numbers upto a range to give correct sum
    for(int i = 0; i < ops.size(); ++i) {
        // fflush(stdout)
        for(int j = i+1; j< (int) ops.size() ; ++j) {
            //swap(ops[i].c,ops[j].c);
            cout<<i<<" "<<j<<endl;
            bool ok = true; 
            for(int k = 0; k < 45; ++k) {
                long long x = 1LL << k ;
                if(simulate(x,x) != 2*x || (x!=0 && simulate(x+1,x-1) != 2*x) )
                    ok = false;
            }
            // for(int x = 0 ; x < 16 && ok; x++) {
            //     for(int y = 0 ; y <= x && ok; y++) {
            //         if(simulate(x,y) != x+y) {
            //             ok = false;
            //         }
            //     }
            // }
            if(ok) {
                cout<<"[[[ " << i<<", "<<j<<" ]]]"<<endl;
                //cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                break;
            }
            //swap(ops[i].c,ops[j].c);
        }
    }

    for(int i = 0; i<8;++i) {
        cout<<swaps[i]<<",\n"[i==7];
    }

}