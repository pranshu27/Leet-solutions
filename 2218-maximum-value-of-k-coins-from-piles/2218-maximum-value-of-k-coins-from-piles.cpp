class Solution {
public:
    int solve(int index, vector<vector<int>>& piles, int k, vector<vector<int>> &dp)
    {
        if(index >= piles.size() || k == 0) return dp[index][k] = 0;
        
        if(dp[index][k]!=-1) return dp[index][k];
        int ans = max(0, solve(index+1, piles, k, dp));
        
        int sum=0;
        for(int i=0; i<piles[index].size(); i++){
            sum+=piles[index][i];
            if(k-i-1 >= 0)ans = max(ans, sum + solve(index+1, piles, k-i-1, dp));
        }
        
        return dp[index][k] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        vector<vector<int>> dp(piles.size()+1, vector<int>(k+1, -1));
        return solve(0, piles, k, dp);
    }
};