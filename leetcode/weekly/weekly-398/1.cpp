class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        int n = nums.size();
        int parity[2] = {-1, -1};
        parity[0] = nums[0] % 2;
        for (int i = 1; i < n; i++)
        {
            parity[i % 2] = nums[i] % 2;
            if (parity[0] == parity[1])
                return false;
        }
        return true;
    }
};