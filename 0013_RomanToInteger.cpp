class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp[s[i + 1]] <= mp[s[i]])
                res += mp[s[i]];
            else
                res -= mp[s[i]];
        }
        res += mp[s.length() - 1];
        return res;
    }
};