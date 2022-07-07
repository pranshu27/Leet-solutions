class Solution {
public:
    int dp[101][101][201];
    bool solve(int i, int j, int k, int n1, int n2, int n3, string &s1, string &s2, string &s3)
    {
        if(i==n1 && j==n2 && k==n3) return true;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        if(i<n1 && s1[i] == s3[k] && solve(i+1, j, k+1, n1, n2, n3, s1, s2, s3)) return dp[i][j][k]=true;
        if(j<n2 && s2[j] == s3[k] && solve(i, j+1, k+1, n1, n2, n3, s1, s2, s3)) return dp[i][j][k]=true;
        
        return dp[i][j][k]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int p = s3.size();

        memset(dp, -1, sizeof(dp));
        if(m+n != p) return false;        
        return solve(0,0,0,m,n,p,s1,s2,s3);
        
        
    }
};