class Solution {
public:
    
    int n;
    
    int solve(int i, int j, vector<vector<int>>& pairs, vector<vector<int>> &dp)
    {
        if(j<0) return 0;
        
        if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];
        
        int take = 0, nottake = 0;
        
        if(i==n || pairs[i][0] > pairs[j][1])
            take = 1+solve(j, j-1, pairs, dp);
        nottake = solve(i, j-1, pairs, dp);
        
        return dp[i+1][j+1] = max(take, nottake);
        
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1]<b[1];
        });
        vector<vector<int>> dp(1001, vector<int>(1001,-1));
        
        n = pairs.size();
        return solve(n, n-1, pairs, dp);
    }
};