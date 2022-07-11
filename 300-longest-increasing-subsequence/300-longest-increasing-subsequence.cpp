int solve(int i, int j, const vector<int> &a, int n, vector<vector<int>> &dp)
{
    if(j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int len = 0;
    if(i==n||a[i]>a[j]){
        len = 1+ ((j>1&&dp[j][j-1]>0)? dp[j][j-1]: solve(j, j-1, a, n, dp));
    }
    len = max(len, ((j>1&&dp[i][j-1]>0)? dp[i][j-1]: solve(i, j-1, a, n, dp)));
    return dp[i][j] = len;
}


class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        int n = A.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n, n-1, A, n, dp);
    }
};

