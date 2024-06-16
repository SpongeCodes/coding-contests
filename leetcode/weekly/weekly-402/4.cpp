#include<bits/stdc++.h>
using namespace std;

// segment tree solution with my template
class Solution {
private:
static int op(int a, int b) {
    return a+b;
}
static int E() {
    return 0;
}
template<typename T, T (*op)(T,T), T (*e) ()>
class SegmentTree {
    // iterative segment tree
    public:
    std::vector<T> d;
    int n; 
    SegmentTree(int n) : SegmentTree(std::vector<T>(2*n,e())) {}
    SegmentTree(const vector<T> & v): n(v.size()), d(2*v.size()) {
        // build the segment tree
        for(int i=1;i<n-1;++i) d[i+n] = v[i];
        for(int i=n-1;i>0;--i) d[i] = op(d[2*i],d[2*i+1]);
    }

    void build(const vector<T> & v) {
        for(int i=0;i<n;++i) d[i+n] = v[i];
        for(int i=n-1;i>0;--i) d[i] = op(d[2*i],d[2*i+1]);
    }

    T prod(int l, int r) {
        // get range from l to r exclusive
        l+=n, r+=n;
        T tl = e(), tr = e();
        while(l<r) {
            if(l&1) tl = op(tl,d[l++]);
            if(r&1) tr = op(d[--r],tr);
            l>>=1;
            r>>=1;
        }
        return op(tl,tr);
    }
    void update(int p, int value) {  // set value at position p
        for (d[p += n] = value; p > 1; p >>= 1) d[p>>1] = op(d[p],d[p^1]);
    }
};
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        // create peaks array with
        int n = nums.size();
        SegmentTree<int,Solution::op,Solution::E> st(n);
        for(int i=1;i<n-1;i++) {
            st.update(i,(nums[i]>nums[i-1] && nums[i]>nums[i+1]));
        }   
        for(auto &q: queries) {
            if(q[0]==2) {
                int val = q[2];
                int p=q[1];
                nums[p] = val;
                if(p>0 && p<n-1) st.update(p,(nums[p]>nums[p-1] && nums[p]>nums[p+1]));
                if(p>1) st.update(p-1,(nums[p-1]>nums[p-2] && nums[p-1]>nums[p]));
                if(p<n-2) st.update(p+1,(nums[p+1]>nums[p] && nums[p+1]>nums[p+2]));
            }
            else{
                int l = q[1], r= q[2];
                ans.push_back(st.prod(l+1,r));
            }
        } 
        return ans;
    }
};

// fenwick tree solution (CREDIT:  VOTRUBAC)
class Solution {
    constexpr int static n = 100000;
    int bt[n + 1] = {};
    int psum(int i) {
        int sum = 0;
        for (i = i + 1; i > 0; i -= i & (-i))
            sum += bt[i];
        return sum;
    }
    void add(int i, int val) {
        for (i = i + 1; i <= n; i += i & (-i))
            bt[i] += val;
    }
    public:
    vector<int> countOfPeaks(vector<int>& n, vector<vector<int>>& queries) {
        auto isPeak = [&](int i) {
            return i > 0 && i + 1 < n.size() && n[i - 1] < n[i] &&
                   n[i] > n[i + 1];
        };
        for (int i = 1; i + 1 < n.size(); ++i)
            if (isPeak(i))
                add(i, 1);
        vector<int> res;
        for (const auto& q : queries)
            if (q[0] == 1)
                res.push_back(q[2] - q[1] < 2
                                  ? 0
                                  : psum(q[2]) -
                                        (q[1] == 0 ? 0 : psum(q[1] - 1)) -
                                        isPeak(q[1]) - isPeak(q[2]));
            else {
                int prev[3] = {}, i = q[1];
                for (int p = -1; p < 2; ++p)
                    prev[p + 1] = isPeak(i + p);
                n[i] = q[2];
                for (int p = -1; p < 2; ++p)
                    if (prev[p + 1] != isPeak(i + p))
                        add(i + p, prev[p + 1] ? -1 : 1);
            }
        return res;
    }
};