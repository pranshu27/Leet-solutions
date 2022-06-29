class Solution {
public:
 
    int maxProfit(int k, vector<int>& prices) {
        int dp[prices.size()+1][2*k+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=prices.size()-1; i>=0; i--){
            for(int j=2*k-1; j>=0; j--){
                if(j%2==0){
                    dp[i][j] = max(-prices[i]+dp[i+1][j+1],  dp[i+1][j]);
                }
                else{
                    dp[i][j] = max(prices[i]+dp[i+1][j+1],  dp[i+1][j]);
                }
                
            }
        }
         
        return dp[0][0];
    }
};

