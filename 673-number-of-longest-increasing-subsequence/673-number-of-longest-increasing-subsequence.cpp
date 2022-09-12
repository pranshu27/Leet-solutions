class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), count(n,1);
        int maxx = INT_MIN;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j] && dp[i]<dp[j]+1)
                    {dp[i] = dp[j]+1;
                    count[i] = count[j];}
                else if(nums[i]>nums[j] && dp[i]==dp[j]+1)
                    count[i]+=count[j];
            }
            maxx = max(maxx, dp[i]);
        }
        
        
        int out = 0;
        for(int i=0; i<n; i++) if(dp[i]==maxx) out+=count[i];
        return out;
    }
};