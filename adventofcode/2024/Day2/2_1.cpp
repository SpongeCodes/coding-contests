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
        for(int i=1;i<n;i++) {
            if(a[i]==a[i-1]) {
                f=false;
                break;
            }
            if(a[i]>a[i-1] && a[i] > a[i-1]+3) {
                f= false; break;
            }
            if(a[i]<a[i-1] && a[i] < a[i-1]-3) {
                f= false; break;
            }
            if(i>1 && a[i-1]<a[i] && a[i-2]>a[i-1]) {
                f=false; break;
            }
            if(i>1 && a[i-1] > a[i] && a[i-2]<a[i-1]) {
                f=false; break;
            }
        }
        if(f) safe++;
    }

    cout<<safe<<endl;

    return 0;
}