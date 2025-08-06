#include <vector>
#include <unordered_map>
#include <string>
#include <bitset>
using namespace std;

class Solution {
public:
    // Approach 1: Using fixed-size array (Fastest and most memory efficient)
    // Time: O(n), Space: O(1)
    // This approach uses a fixed-size array of 100 elements because:
    // - The maximum possible key is 99 (when both numbers are 9: 9*10 + 9 = 99)
    // - The minimum possible key is 11 (when both numbers are 1: 1*10 + 1 = 11)
    // We first count all occurrences, then calculate pairs in a second pass
    int numEquivDominoPairs_array(vector<vector<int>>& dominoes) {
        // Initialize array to count occurrences of each unique domino
        // Index represents the unique key for each domino type
        vector<int> count(100, 0);
        int res = 0;
        
        // First pass: Count occurrences of each unique domino
        for (auto& d : dominoes) {
            // Create a unique key by putting smaller number first
            // This ensures [1,2] and [2,1] get the same key (12)
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            count[key]++;
        }
        
        // Second pass: Calculate number of pairs for each domino type
        // For n occurrences of a domino, there are n*(n-1)/2 possible pairs
        for (auto cnt : count) {
            if (cnt > 1) {
                res += cnt * (cnt - 1) / 2;
            }
        }
        
        return res;
    }

    // Approach 2: Using unordered_map (More flexible for larger numbers)
    // Time: O(n), Space: O(n)
    // This approach uses a hash map instead of a fixed array
    // Advantage: Can handle larger numbers beyond 1-9
    // Disadvantage: Slightly slower due to hash map operations
    int numEquivDominoPairs_map(vector<vector<int>>& dominoes) {
        // Map to store count of each unique domino
        unordered_map<int, int> count;
        int res = 0;
        
        // Single pass: Count and calculate pairs simultaneously
        for (auto& d : dominoes) {
            // Create unique key same as in array approach
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            // Add current count to result before incrementing
            // This works because:
            // - First occurrence: count[key] is 0, adds 0
            // - Second occurrence: count[key] is 1, adds 1
            // - Third occurrence: count[key] is 2, adds 2
            // And so on...
            res += count[key]++;
        }
        
        return res;
    }

    // Approach 3: Using string keys (Most readable but slower)
    // Time: O(n), Space: O(n)
    // This approach uses strings as keys in the map
    // Advantage: Very readable and easy to debug
    // Disadvantage: String operations are slower than integer operations
    int numEquivDominoPairs_string(vector<vector<int>>& dominoes) {
        // Map using string keys like "1,2" instead of integer 12
        unordered_map<string, int> count;
        int res = 0;
        
        for (auto& d : dominoes) {
            // Create string key by concatenating numbers with comma
            // This makes it very clear what the key represents
            string key = to_string(min(d[0], d[1])) + "," + to_string(max(d[0], d[1]));
            // Same counting logic as map approach
            res += count[key]++;
        }
        
        return res;
    }

    // Approach 4: Using bitset (Memory efficient but less readable)
    // Time: O(n), Space: O(1)
    // This approach uses a bitset to track which domino types we've seen
    // Advantage: Extremely memory efficient (1 bit per possible domino)
    // Disadvantage: More complex logic, less readable
    int numEquivDominoPairs_bitset(vector<vector<int>>& dominoes) {
        // Bitset to track which domino types we've seen
        // Each bit represents whether we've seen that domino type
        bitset<100> seen;
        // Array to count occurrences (could use map instead)
        vector<int> count(100, 0);
        int res = 0;
        
        for (auto& d : dominoes) {
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            if (seen[key]) {
                // If we've seen this domino before, add current count to result
                res += count[key]++;
            } else {
                // First time seeing this domino type
                seen[key] = true;  // Mark as seen
                count[key] = 1;    // Initialize count to 1
            }
        }
        
        return res;
    }

    // Approach 5: One-pass array solution (Most efficient for this problem)
    // Time: O(n), Space: O(1)
    // This is the recommended solution for this specific problem
    // Combines the best of array approach (speed) and map approach (single pass)
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // Fixed-size array for counting
        vector<int> count(100, 0);
        int res = 0;
        
        // Single pass through dominoes
        for (auto& d : dominoes) {
            // Create unique key
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            // Add current count to result before incrementing
            // This is the same logic as the map approach but using array
            res += count[key]++;
        }
        
        return res;
    }
};