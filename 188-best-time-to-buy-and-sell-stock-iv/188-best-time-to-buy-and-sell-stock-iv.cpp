class Solution {
public:
    int dp[210][100001];
    int solve(vector<int>& prices, int tran, int i, int k)
    {
        if(i==prices.size() || tran == 2*k) return dp[tran][i] = 0; 
        
        if(dp[tran][i]!=-1) return dp[tran][i];
        
        int a = (dp[tran+1][i+1]!=-1? dp[tran+1][i+1]:solve(prices, tran+1, i+1, k));
        int b = (dp[tran][i+1]!=-1? dp[tran][i+1]:solve(prices, tran, i+1, k));
        
        if(tran%2==0) return dp[tran][i] = max(-prices[i]+a, b);
        else
        {
            return dp[tran][i] = max(prices[i]+a, b);
        }
        
        
    }
    int maxProfit(int k, vector<int>& prices) {
         memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 0, k);
    }
};

