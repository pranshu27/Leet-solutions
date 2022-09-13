class Solution {
public:
     int solve(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>> arr)
    {
         if(i>=m || j>=n || arr[i][j]==1) return dp[i][j] = 0;
        if(i==m-1 && j==n-1) return dp[i][j] = 1;

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = solve(i+1, j, m, n, dp, arr)+
            solve(i, j+1, m, n, dp, arr);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        vector<vector<int>> dp(101, vector<int>(101, -1));
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return solve(0,0,m,n, dp, obstacleGrid);
    }
};