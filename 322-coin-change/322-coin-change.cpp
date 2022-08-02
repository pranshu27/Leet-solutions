class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1));
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<amount+1; j++){
                if(j==0) dp[i][j] = 0;
                else if(i==0) dp[i][j] = INT_MAX-1;
                else if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount] == (INT_MAX-1)? -1 : dp[n][amount];
    }
};