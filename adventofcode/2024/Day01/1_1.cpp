#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    ifstream inputfile("texts/input.txt");
    string line;
    vector<int> a,b;
    while(getline(inputfile,line)) {
        //cout<<line<<endl;
        int e1 = line.find_first_of(' '), e2 = line.find_last_of(' ');
        a.push_back(stoi(line.substr(0,e1)));
        b.push_back(stoi(line.substr(e2+1)));
    }

    long long res = 0, sz = a.size();
    for(int i=0;i<sz;++i) res+= 1ll* abs(a[i]-b[i]);
    cout<<res<<endl;

    return 0;
}