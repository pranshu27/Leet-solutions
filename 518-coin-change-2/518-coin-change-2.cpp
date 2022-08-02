class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        int n = amount;
        long long int dp[m+1][n+1];
        
        for(int i=0; i<m+1;i++)
        {
            for(int j=0; j<n+1; j++)
            {
                if(j==0) dp[i][j]=1; //sum lena hai 0 to null coin array le skte hain
                else if(i==0) dp[i][j]=0;
                else if(coins[i-1]<=j){
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]]; //unbounded knapsack
                }
                else dp[i][j] = dp[i-1][j];
            } 
        }
        
        return dp[m][n];
    }
};