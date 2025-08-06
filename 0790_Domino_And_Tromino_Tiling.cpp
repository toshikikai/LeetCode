#include <vector>

class Solution {
public:
    int numTilings(int n) {
        if (n <= 2) return n;
        
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        vector<long long> dp_partial(n + 1, 0);
        
        // Base cases
        dp[1] = 1;  // One vertical domino
        dp[2] = 2;  // Two vertical dominoes or two horizontal dominoes
        dp_partial[2] = 1;  // One tromino
        
        for (int i = 3; i <= n; i++) {
            // Full tiling: 
            // 1. Add vertical domino to dp[i-1]
            // 2. Add two horizontal dominoes to dp[i-2]
            // 3. Add tromino to dp_partial[i-1] (two ways)
            dp[i] = (dp[i-1] + dp[i-2] + 2 * dp_partial[i-1]) % MOD;
            
            // Partial tiling:
            // 1. Add horizontal domino to dp[i-2]
            // 2. Add tromino to dp[i-1]
            dp_partial[i] = (dp[i-2] + dp_partial[i-1]) % MOD;
        }
        
        return dp[n];
    }
};
