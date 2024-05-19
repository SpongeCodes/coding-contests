class Solution
{
public:
    long long sumDigitDifferences(vector<int> &nums)
    {
        vector<vector<int>> dig(10, vector<int>(10, 0));
        for (int i : nums)
        {
            int n = i;
            int cnt = 0;
            while (n)
            {
                dig[cnt++][n % 10]++;
                n /= 10;
            }
        }
        long long res = 0;
        // for every digit count diff
        for (int digit = 0; digit < 10; digit++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (dig[digit][j] == 0)
                    continue;
                for (int k = 0; k < 10; k++)
                {
                    if (j == k)
                        continue;
                    res += dig[digit][j] * dig[digit][k];
                }
            }
        }
        return res / 2;
    }
};