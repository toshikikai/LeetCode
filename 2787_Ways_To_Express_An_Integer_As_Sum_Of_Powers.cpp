#include<vector>
using namespace std;

class Solution {
private:
    const int MOD = 1000000007;

    long long power(int base, int x) {
        long long result = 1;
        for (int i = 0; i < x; i++) {
            result *= base;
        }
        return result;
    }

public:
    int numberOfWays(int n, int x) {
         int maxNum = 1;
        while (power(maxNum, x) <= n) {
            maxNum++;
    }
    maxNum--;

    vector<vector<int>> dp(n+1,vector<int>(maxNum+1,0));
    for(int j=0;j<=maxNum;j++) {
        dp[0][j] = 1;
    }
    for(int k=1;k<=n;k++) {
        for(int j=1;j<=maxNum;j++) {
            // Don't use j
            dp[k][j] = dp[k][j-1];

            // Use j
            long long powerVal = power(j,x);
            if(k >= powerVal) {
                dp[k][j] = (dp[k][j-1] + dp[k-powerVal][j-1])%MOD;
            }
        }
    }
    return dp[n][maxNum];
    }
};
