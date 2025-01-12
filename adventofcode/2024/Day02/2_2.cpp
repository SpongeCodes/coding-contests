#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    ifstream inputfile("input.txt");
    string line;
    int safe = 0;
    while(getline(inputfile,line)) {
        //cout<<line<<endl;
        vector<int> a;
        bool f = true;
        string s;
        stringstream ss(line);
        while(getline(ss,s,' ')) {
            a.push_back(stoi(s));
        }
        int n = a.size();
        for(int j=0;j<n;j++) {
            int i;
            for(i=1;i<n;++i) {
                
                if(i==j) continue;
                int prev = -1, next = -1;
                prev = (i-1!=j)? a[i-1]: (i>1)? a[i-2]: -1;
                next = (i+1<n && i+1!=j)? a[i+1]: (i+2<n)? a[i+2]: -1;
                if(prev!=-1 && (prev==a[i] || prev<a[i]-3 || prev>a[i]+3)) {
                    break;
                }
                if(next!=-1 && (next==a[i] || next<a[i]-3 || next>a[i]+3)) {
                    break;
                }
                if(prev!=-1 && next!=-1 && prev<a[i] && a[i]>next) {
                    break;
                }
                if(prev!=-1 && next!=-1 && prev>a[i] && a[i]<next) {
                    break;
                }
            }
            if(i==n) {
                safe++;
                break;
            }
        }
    }

    cout<<safe<<endl;

    return 0;
}