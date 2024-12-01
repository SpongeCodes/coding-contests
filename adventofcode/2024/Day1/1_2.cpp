#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    ifstream inputfile("texts/input.txt");
    string line;
    unordered_map<long long,int> a,b;
    while(getline(inputfile,line)) {
        //cout<<line<<endl;
        int e1 = line.find_first_of(' '), e2 = line.find_last_of(' ');
        a[stoi(line.substr(0,e1))]++;
        b[stoi(line.substr(e2+1))]++;
    }

    long long res = 0;
    for(auto &[i,cnt]: a) res+= 1ll*i*cnt*b[i];
    cout<<res<<endl;

    return 0;
}