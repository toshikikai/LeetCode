class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n <= 2) return n;
        
        unordered_map<int, int> basket;
        int left = 0, maxFruits = 0;
        
        for (int right = 0; right < n; right++) {
            // Add current fruit to basket
            basket[fruits[right]]++;
            
            // If we have more than 2 types of fruits, remove from left
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            
            // Update maximum fruits collected
            maxFruits = max(maxFruits, right - left + 1);
        }
        
        return maxFruits;
    }
}; 