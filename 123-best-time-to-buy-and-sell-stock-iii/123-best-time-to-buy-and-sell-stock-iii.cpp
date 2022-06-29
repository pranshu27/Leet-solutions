class Solution {
public:
    int dp[10][100001];
    int solve(vector<int>& prices, int tran, int i, int k)
    {
        if(i==prices.size() || tran == 2*k) return dp[tran][i] = 0; 
        
        if(dp[tran][i]!=-1) return dp[tran][i];
        
        if(tran%2==0) return dp[tran][i] = max({
            -prices[i] + solve(prices, tran+1, i+1, k),
            solve(prices, tran, i+1, k),
            
        });
        else
        {
            return dp[tran][i] = max({
            prices[i] + solve(prices, tran+1, i+1, k),
            solve(prices, tran, i+1, k),
            
        });
        }
        
        
    }
    int maxProfit(vector<int>& prices) {
       
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 0, 2);
    }
};