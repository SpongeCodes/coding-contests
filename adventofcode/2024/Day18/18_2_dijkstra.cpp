#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 71;

int main() {
    // DIJKSTRA SOLUTION TO SOLVE IN LINEAR TIME O(N^2)
    vector<pair<int,int>> v;
    int x,y;
    const int MAX = 3450;
    vector<vector<int>> dist(N,vector<int>(N,0));
    vector<vector<int>> id(N,vector<int>(N,MAX+1));
    bool vis[N][N];
    int t = 1;
    while(scanf("%d,%d",&x,&y) !=EOF) {
        v.emplace_back(x,y);
        id[x][y] = t++; 
    }
    //cout<<t-1<<endl;
    vector<pair<int,int>> inv[MAX+2];
    dist[0][0] = id[0][0];
    inv[dist[0][0]].emplace_back(0,0);
    for(int V=MAX+1;V>=0;--V) {
        for(int z = 0 ; z < (int) inv[V].size(); ++z) {
            pair<int,int> me = inv[V][z];
            int r = me.first, c = me.second;
            if(dist[r][c] != V) {
                continue;
            }
            for(pair<int,int> dir: vector<pair<int,int>> {{0,-1},{-1,0},{0,1},{1,0}}) {
                int r2 = r+ dir.first;
                int c2 = c+ dir.second;
                if(0<=min(r2,c2) && max(r2,c2)<N) {
                    int x = min(V,id[r2][c2]);
                    if(x>dist[r2][c2]) {
                        dist[r2][c2]  = x;
                        inv[x].emplace_back(r2,c2);
                    }
                }
            }
        }
    }
    int finalId = dist[N-1][N-1];
    cout<<v[finalId-1].first<<","<<v[finalId-1].second<<endl;
    return 0;
}