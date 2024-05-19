class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<bool> res;
        int n = nums.size();
        // find invalid indices upto an index
        vector<int> pref(n + 1, 0);
        for (int i = 2; i <= n; i++)
        {
            pref[i] = pref[i - 1] + ((nums[i - 1] & 1) == (nums[i - 2] & 1));
        }
        for (auto &q : queries)
        {
            bool qu = (pref[q[1] + 1] - pref[q[0] + 1]) == 0;
            res.push_back(qu);
        }
        return res;
    }
};