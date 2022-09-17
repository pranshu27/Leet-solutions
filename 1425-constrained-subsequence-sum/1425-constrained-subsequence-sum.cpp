class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
		deque<int> d;
        vector<int> dp(n, 0);

        for(int i=0; i<n; i++)
        {
            while(!d.empty() && i-d.front()>k) d.pop_front();
            dp[i]=nums[i];
            if(!d.empty()) dp[i] = max(dp[i], dp[i]+dp[d.front()]);
            
            while(!d.empty() && dp[d.back()]<=dp[i]) d.pop_back();
            d.push_back(i);

        }
        
        int maxx = INT_MIN;
        for(auto &it: dp) maxx = max(maxx, it);
        return maxx;
    }
};