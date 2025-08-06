class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        if (n <= 2)
            return n;
        unordered_map<int, int> basket;
        int left = 0, maxFruits = 0;
        for (int right = 0; right < n; right++)
        {
            basket[fruits[right]]++;
            while (basket.size() > 2)
            {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            maxFruits = max(maxFruits, right - left + 1);
        }
        return maxFruits;
    }
};