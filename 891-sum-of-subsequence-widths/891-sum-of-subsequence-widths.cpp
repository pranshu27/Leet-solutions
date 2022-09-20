class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        long long ans = 0;
        int mod = 1e9+7;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<long long> power(n+1, 0);
        power[0]=1;
        
        for(int i = 1; i<n; i++)
        {
            power[i] = power[i-1]*2;
            power[i]%= mod;
        }
        
        for(int i=0; i<n; i++)
        {
            ans += (power[i] - power[n-i-1])*nums[i];
            ans %= mod;
        }
        
        return ans;
    }
    
    
};