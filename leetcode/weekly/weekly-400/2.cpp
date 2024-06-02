class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        int last = 1, ans = 0;
        sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b) -> bool
             { return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]); });
        for (auto &meeting : meetings)
        {
            // cout<<meeting[0]<<" "<<meeting[1]<<endl;
            if (meeting[0] >= last)
            {
                ans += meeting[0] - last;
                last = meeting[1] + 1;
                continue;
            }
            if (meeting[1] >= last)
            {
                last = meeting[1] + 1;
            }
        }
        ans += max(0, days - last + 1);
        return ans;
    }
};