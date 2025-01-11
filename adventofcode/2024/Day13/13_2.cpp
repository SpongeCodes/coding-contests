#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll res = 0;
    char s[105];
    while(scanf("%s",s) != EOF) {
        int ax,ay,bx,by;
        ll px,py;
        scanf("%s",s);
        scanf(" X+%d,",&ax);
        scanf(" Y+%d,",&ay);
        scanf("%s",s);
        scanf("%s",s);
        scanf(" X+%d,",&bx);
        scanf(" Y+%d,",&by);
        scanf("%s",s);
        scanf(" X=%lld,",&px);
        scanf(" Y=%lld,",&py);
        px += 1e13, py += 1e13;
        // ax*i+bx*j = px
        // ay*i+by*j = py
        // i = (px*by-py*bx)/(ax*by-ay*bx)
        // j = (px*ay-py*ax)/(bx*ay-by*ax)
        cout<<"A = "<<(px*by-py*bx)/(ax*by-ay*bx);
        cout<<" B = "<<(px*ay-py*ax)/(bx*ay-by*ax)<<endl;
        if(ax*by-ay*bx != 0 && (px*by-py*bx)%(ax*by-ay*bx) == 0) {
            ll i = (px*by-py*bx)/(ax*by-ay*bx);
            ll j = (px*ay-py*ax)/(bx*ay-by*ax);
            if(i*ax+j*bx==px && i*ay+j*by==py)
                res += 3*i+j;
        }
    }   
    cout<<res<<endl;
    return 0;
}