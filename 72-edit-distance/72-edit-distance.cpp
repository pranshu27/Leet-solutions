class Solution {
public:
    int dp[501][501];
    
    
    int f(string s, string t, int m, int n)
    {
        if(m==-1) return n+1;
        if(n==-1) return m+1;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(s[m] == t[n]) return dp[m][n] = f(s,t,m-1, n-1);
        
        int a,b,c;
        
        a = f(s, t, m-1, n-1); //replace
        b = f(s,t,m,n-1); //insert
        c = f(s,t,m-1,n); //remove
        
        return dp[m][n] = 1 + min(a, min(b,c));
    }
    
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min(
                        dp[i][j-1],
                        min(
                            dp[i-1][j],
                            dp[i-1][j-1]
                        )
                    )+1;
                }
            }
        }
        return dp[n][m];
    }
};