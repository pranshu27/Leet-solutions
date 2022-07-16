class Solution {
public:
    int mod  = 1e9 + 7;
    int solve(int &m, int &n, int maxMove, int i, int j, vector<vector<vector<int>>> &dp)
    {
        if(i>=m || j>=n || i<0 || j<0) return dp[maxMove+1][i+1][j+1] = 1;
        
        if(dp[maxMove+1][i+1][j+1]!=-1) return dp[maxMove+1][i+1][j+1]%mod;
        
        long long ans = 0;
        if(maxMove){
            ans += (solve(m,n,maxMove-1, i-1, j, dp));
            ans %= mod;
            ans += (solve(m,n,maxMove-1, i, j-1, dp));
            ans %= mod;
            ans += (solve(m,n,maxMove-1, i+1, j, dp));
            ans %= mod;
            ans += (solve(m,n,maxMove-1, i, j+1, dp));
            ans %= mod;
        }
        return dp[maxMove+1][i+1][j+1]= ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
    vector<vector<vector<int>>> dp(maxMove + 2, vector<vector<int>> (m + 2, vector<int> (n + 2, -1)));

        return solve(m, n, maxMove, startRow, startColumn, dp);
        //return -1;
    }
};