class Solution {
public:
    
    int countVowelPermutation(int n) {
        
        vector<long long> curr(5, 1);
        vector<long long> after(5, 1);
        
        int mod = 1e9+7;
        for(int i=1; i<n; i++)
        {

            curr[0] = (after[4]%mod + after[1]%mod + after[2]%mod)%mod; //words ending at a
            curr[1] = (after[0]%mod + after[2]%mod)%mod;
            curr[2] = (after[1]%mod + after[3]%mod)%mod;
            curr[3] = (after[2]%mod)%mod;
            curr[4] = (after[2]%mod + after[3]%mod)%mod;
            after = curr;

        }
        
        long long ans = 0;
        for(int i=0; i<5; i++) {
            ans += curr[i]%mod;
            ans %= mod;
        }
        return ans%mod;
    }
};