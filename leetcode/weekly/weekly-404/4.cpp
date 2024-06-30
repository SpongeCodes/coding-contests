#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
private:
    int getDiameter(vector<vector<int>>& tree) {
        // 2 BFS
        queue<pair<int, int>> q;
        q.push({0, -1});
        int diameter = -1, lastNode = -1;
        while (!q.empty()) {
            pair<int, int> f = q.front();
            q.pop();
            int u = f.first, par = f.second;
            lastNode = u;
            for (auto& v : tree[u]) {
                if (v == par)
                    continue;
                q.push({v, u});
            }
        }
        // 2nd bfs to get diameter from farthest node
        q.push({lastNode, -1});
        while (!q.empty()) {
            diameter++;
            int sz = q.size();
            for (int i=0;i<sz;++i) {
                pair<int, int> f = q.front();
                q.pop();
                int u = f.first, par = f.second;
                for (auto& v : tree[u]) {
                    if (v == par)
                        continue;
                    q.push({v, u});
                }
            }
        }
        return diameter;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // radius is ceil(diameter/2)
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> tree1(n), tree2(m);
        for (auto& e : edges1) {
            tree1[e[0]].push_back(e[1]);
            tree1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            tree2[e[0]].push_back(e[1]);
            tree2[e[1]].push_back(e[0]);
        }
        int da = getDiameter(tree1), db = getDiameter(tree2);
        int ra = (da + 1) / 2, rb = (db + 1) / 2;

        return max({ra + rb + 1, da, db});
    }
};
