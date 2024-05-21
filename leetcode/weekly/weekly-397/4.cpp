class Solution {
private:
int f(int mask,int last,int n, vector<int> &nums,
                vector<vector<int>> &dp) {
    // you can fix first index as 0
    if(last == -1) {
        return f(1,0,n,nums,dp);
    }
    if(mask == (1<<n)-1) {
        // add 0 
        return  abs(last-nums[0]);
    }
    if(dp[mask][last] != -1) return dp[mask][last];
    int res = 200;
    for(int j=0;j<n;j++) {
        // get minimum of all and
        if((mask>>j) & 1) continue;
        int newMask = mask | (1<<j); 
        res = min(res, f(newMask,j,n,nums,dp) + abs(last-nums[j]));
    }
    return dp[mask][last] = res;
}
public:
    vector<int> findPermutation(vector<int>& nums) {
        // bitmask dp
        int n = nums.size();
        vector<vector<int>> dp(1<<n,vector<int>(n,-1));
        cout<<f(0,-1,n,nums,dp)<<endl;
        // for every mask starting from 001 to 111..
        // find the least unset bit which contributes to minimum dp
        vector<int> res;
        int currentMask = 1, current = 0, finalMask = (1<<n) - 1;
        res.push_back(0);
        while(currentMask != finalMask) {
            int last = -1, MIN=200;
            for(int j=0;j<n;j++) {
                if((currentMask>>j)&1) continue;
                int newMask = currentMask | (1<<j);
                if(dp[newMask][j] + abs(current-nums[j]) < MIN) {
                    last = j;
                    MIN = dp[newMask][j] + abs(current-nums[j]);
                }
            }
            currentMask |= (1<<last);
            current = last;
            res.push_back(last);
        }
        return res;
    }
};