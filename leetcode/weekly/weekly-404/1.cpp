#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int h1 = 1, h2=1 ;
        int r1=red,r2=red,b1=blue,b2=blue;
        while(true) {
            //cout<<b1<<" "<<r1<<" "<<h1<<endl;
            // WHILE USING AND OPERATOR (&) -> REMEMBER TO USE () DUE TO OPERATOR PRECEDENCE '==' before and
            if(h1%2==1 && h1>b1) {
                h1--;
                break;
            }
            if(h1%2==0 && h1>r1) {
                h1--;
                break;
            }
            if(h1%2==1) {
                b1-=h1;
            }
            else {
                r1-=h1;
            }
            h1++;
        }
        while(true) {
            //cout<<b2<<" "<<r2<<" "<<h2<<endl;
            if(h2%2==1 && h2>r2) {
                h2--;
                break;
            }
            if(h2%2==0 && h2>b2) {
                h2--;
                break;
            }
            if(h2%2==1) {
                r2-=h2;
            }
            else {
                b2-=h2;
            }
            h2++;
        }

        return max(h1,h2);
    }
};