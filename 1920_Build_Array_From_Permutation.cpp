#include <vector>
using namespace std;

class Solution {
public:
    // Original O(n) space solution
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            ans[i]=nums[nums[i]];
        }
        return ans;
    }
    
    // O(1) space solution using mathematical trick
    vector<int> buildArray_O1(vector<int>& nums) {
        int n = nums.size();
        // Store both original and new values in the same array
        // Using the formula: new_value = (original_value + n * new_value)
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i] + n * (nums[nums[i]] % n);
        }
        // Extract the new values
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i] / n;
        }
        return nums;
    }

    // Alternative O(1) space solution using bit manipulation
    vector<int> buildArray_bit(vector<int>& nums) {
        int n = nums.size();
        // Store both values using bit manipulation
        // We can store two 10-bit numbers in a 32-bit integer
        for(int i = 0; i < n; i++) {
            nums[i] |= (nums[nums[i]] & 0x3FF) << 10;
        }
        // Extract the new values
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i] >> 10;
        }
        return nums;
    }

    // Alternative O(1) space solution using negative numbers
    vector<int> buildArray_negative(vector<int>& nums) {
        int n = nums.size();
        // First pass: store both values using negative numbers
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i] + n * (nums[nums[i]] % n);
        }
        // Second pass: make all numbers positive
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i] / n;
        }
        return nums;
    }

    // Alternative solution using a temporary variable
    vector<int> buildArray_temp(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int temp = nums[i];
            nums[i] = nums[nums[i]];
            nums[nums[i]] = temp;
        }
        return nums;
    }

    // Solution for candy distribution problem
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        // For each possible amount for first child
        for(int i = 0; i <= min(n, limit); i++) {
            // For each possible amount for second child
            for(int j = 0; j <= min(n - i, limit); j++) {
                // Third child gets remaining candies
                int k = n - i - j;
                // Check if third child's amount is valid
                if(k >= 0 && k <= limit) {
                    res++;
                }
            }
        }
        return res;
    }
};
