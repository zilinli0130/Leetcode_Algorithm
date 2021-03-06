class Solution {
public:
    int getMoneyAmount(int n) {
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, INT_MAX/2));
       
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= n + 1; j++) {
                if (i == j || i > j) {
                    dp[i][j] = 0;
                }
            }
        }
        
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};