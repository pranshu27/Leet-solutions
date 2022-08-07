class Solution {
public:
    
    int countVowelPermutation(int n) {
        
        vector<vector<long long>> dp(n, vector<long long>(5, 1));
        int mod = 1e9+7;
        for(int i=1; i<n; i++)
        {

            dp[i][0] = (dp[i-1][4]%mod + dp[i-1][1]%mod + dp[i-1][2]%mod)%mod; //words ending at a
            dp[i][1] = (dp[i-1][0]%mod + dp[i-1][2]%mod)%mod;
            dp[i][2] = (dp[i-1][1]%mod + dp[i-1][3]%mod)%mod;
            dp[i][3] = (dp[i-1][2]%mod)%mod;
            dp[i][4] = (dp[i-1][2]%mod + dp[i-1][3]%mod)%mod;

        }
        
        long long ans = 0;
        for(int i=0; i<5; i++) {
            ans += dp[n-1][i]%mod;
            ans %= mod;
        }
        return ans%mod;
    }
};