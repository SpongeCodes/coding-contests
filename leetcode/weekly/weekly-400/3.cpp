class Solution
{
private:
    class Compare
    {
    public:
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        }
    };

public:
    string clearStars(string s)
    {
        // always delete the righmost smallest character
        int n = s.size();
        vector<bool> pos(n, 1);
        // keep track of minimum character and its rightmost position
        // priority queue of min character and max position
        auto comp = [](pair<int, int> &a, pair<int, int> &b) -> bool
        {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                pos[i] = 0;
                pos[pq.top().second] = 0;
                pq.pop();
            }
            else
            {
                pq.push({s[i] - 'a', i});
            }
        }
        string s1 = "";
        for (int i = 0; i < n; ++i)
        {
            if (pos[i])
                s1 += s[i];
        }
        return s1;
    }
};