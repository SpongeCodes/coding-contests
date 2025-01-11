#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int px,py,vx,vy;
    int H = 103, W=101, T=100;
    ll q1=0,q2=0,q3=0,q4=0;
    while(scanf(" p=%d,%d v=%d,%d",&px,&py,&vx,&vy) == 4) {
       px = (px+T*vx);
       while(px < 0) px+=W;
       py = (py+T*vy);
       while(py < 0) py+=H;
       px%=W, py%=H;
       if(px==W/2 || py == H/2) continue;
       if(px>W/2 && py<H/2) q1++;
       if(px<W/2 && py<H/2) q2++;
       if(px<W/2 && py>H/2) q3++;
       if(px>W/2 && py>H/2) q4++;
    }   
    cout<<q1*q2*q3*q4<<endl;
    return 0;
}