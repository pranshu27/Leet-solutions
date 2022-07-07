class Solution {
public:

    bool checkPartitioning(string s) {
        vector<string> tmp;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++) dp[i][i] = 1;
        
        for(int k=2; k<=n; k++)
        {
            for(int i=0; i<n-k+1; i++)
            {
                int j = i+k-1;
                if(s[i] == s[j] && (k==2 || dp[i+1][j-1])) dp[i][j] = 1;
            }
        }
        
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (dp[0][i - 1] && dp[i][j - 1] && dp[j][n - 1])
                    return true;
        return false;
        
        
        
    }
};