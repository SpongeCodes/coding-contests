#include<bits/stdc++.h>
using namespace std;
int main() {
    // define a comparator where 
    map<int,vector<int>> rules;
    string s;
    while(getline(cin,s)) {
        if(s.empty()) continue;
        for(int i=0;i<s.size();++i) {
            // while digit
            int curr = 0;
            while(i<s.size() && isdigit(s[i])) {
                curr = curr*10 + (s[i]-'0');
                i++;
            }
                
        }
    }
}