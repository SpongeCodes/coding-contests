class Solution
{
public:
    int minimumChairs(string s)
    {
        int ans = 0, maxi = 0;
        for (char c : s)
        {
            if (c == 'E')
                maxi++;
            else
                maxi--;
            ans = max(maxi, ans);
        }
        return ans;
    }
};