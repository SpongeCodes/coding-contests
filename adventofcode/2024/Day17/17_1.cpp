#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int A,B,C;
    char ins[50];
    scanf("Register A: %d",&A);
    scanf(" Register B: %d",&B);
    scanf(" Register C: %d",&C);
    scanf(" Program: %s",ins);
    vector<int> operations;
    int len = strlen(ins);
    int curr = 0;
    for(int i=0;i<=len;i++) {
        if(ins[i]==',' || ins[i]=='\0') {
            operations.push_back(curr);
            curr=0;
            continue;
        }
        curr = curr*10+(ins[i]-'0');
    }
    int index = 0, n = operations.size();
    map<int,int> combo;
    combo[1] = 1;
    combo[2] = 2;
    combo[3] = 3;
    combo[4] = A; 
    combo[5] = B;
    combo[6] = C;

    for(int i = 0; i + 1 < n ; i+=2) {
        switch(operations[i]) {
            case 0:
                for(int j=1;j<=combo[operations[i+1]];j++) A/=2;
                combo[4]  = A;
            break;
            
            case 1:
                B = B ^ operations[i+1];
                combo[5] = B;
            break;

            case 2:
                B = combo[operations[i+1]]%8;
                combo[5] = B;
            break;

            case 3:
                if(A!=0) i = operations[i+1]-2;
            break;
            
            case 4:
                B = B ^ C;
                combo[5] = B;
            break;
            
            case 5:
                cout<<combo[operations[i+1]]%8<<",";
            break;
            
            case 6:
                B = A;
                for(int j=1;j<=combo[operations[i+1]];j++) B/=2;
                combo[5]  = B;
            break;
            
            case 7:
                C = A;
                for(int j=1;j<=combo[operations[i+1]];j++) C/=2;
                combo[6]  = C;
            break;
        }

    }

}