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
        memset(dp, -1, sizeof(dp));
        int m = s.size();
        int n = t.size();
        
        return f(s, t, m-1, n-1);
    }
};