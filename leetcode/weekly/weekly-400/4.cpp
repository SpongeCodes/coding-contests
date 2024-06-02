// sparse table + bin-search
// Complexity O(N*logN)

class Solution
{
private:
    long long getRangeAND(vector<vector<int>> &sp, int l, int r)
    {
        int cnt = 0;
        while ((1 << cnt) <= (r - l + 1))
        {
            cnt++;
        }
        cnt--;
        return sp[l][cnt] & sp[r - (1 << cnt) + 1][cnt];
    }

public:
    int minimumDifference(vector<int> &nums, int k)
    {
        long long res = INT_MAX;
        int n = nums.size();
        int cnt = 1;
        while ((1 << cnt) <= n)
        {
            cnt++;
        }
        vector<vector<int>> sparse(n, vector<int>(cnt, INT_MAX));
        // build sparse table
        for (int i = 0; i < n; i++)
            sparse[i][0] = nums[i];
        for (int j = 1; j <= cnt; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
                sparse[i][j] = (sparse[i][j - 1]) & (sparse[i + (1 << (j - 1))][j - 1]);
        }
        // binary search for start index where it is smallest
        for (int i = 0; i < n; i++)
        {

            int l = 0, r = i;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                long long rAND = getRangeAND(sparse, m, i);
                if (rAND == k)
                {
                    return 0;
                }
                if (rAND > k)
                {
                    r = m - 1;
                }
                if (rAND < k)
                {
                    l = m + 1;
                }
                res = min(res, abs(rAND - k));
            }
        }

        return res;
    }
};