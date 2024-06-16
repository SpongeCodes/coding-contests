#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        map<int,int> m;
         int res = 0;
         for(int i: hours) {
            int h  = i%24;
            if(m.count((24-h)%24)) res+=m[(24-h)%24]; 
            m[h]++;
        }
        return res;
    }
};