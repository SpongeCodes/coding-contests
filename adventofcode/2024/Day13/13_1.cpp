#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll res = 0;
    char s[105];
    while(scanf("%s",s) != EOF) {
        int ax,ay,bx,by,px,py;
        scanf("%s",s);
        scanf(" X+%d,",&ax);
        scanf(" Y+%d,",&ay);
        scanf("%s",s);
        scanf("%s",s);
        scanf(" X+%d,",&bx);
        scanf(" Y+%d,",&by);
        scanf("%s",s);
        scanf(" X=%d,",&px);
        scanf(" Y=%d,",&py);
        for(int i=0;i<=100;++i) {
            for(int j=0;j<=100;++j) {
                if(ax*i+bx*j == px && ay*i+by*j == py) res += 3*i+j;
            }
        }
        // cout<<"ax = "<<ax<<" ay = "<<ay<<" bx= "<<bx<<" by= "<<by;
        // cout<<" px = "<<px<<" "<<"py = "<<py<<endl;
    }   
    cout<<res<<endl;
    return 0;
}