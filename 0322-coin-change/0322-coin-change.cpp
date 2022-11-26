class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m = coins.size(), n = amount;
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        
        for(int i=0; i<=m; i++)
        {
            for(int j = 0; j<=n; j++){
                if (j==0) dp[i][j] = 0;
                else if(i==0) dp[i][j] = INT_MAX-1;
                
                else if(coins[i-1]<=j){
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[m][n] == INT_MAX-1? -1:  dp[m][n];
    }
};