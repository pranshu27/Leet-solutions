class Solution {
public:
    
    int solve(vector<int>& nums, int index, int prev_index, int &k, vector<vector<int>> &dp) {
       
        if(index == nums.size() || (prev_index!=-1 && index-prev_index>k))
            return 0;
        
        if(dp[index][prev_index+1]!=-1) return dp[index][prev_index+1];

        int take = 0, nottake = 0;
        
        if(prev_index==-1 || index-prev_index<=k)
        {
            take = dp[index+1][index+1] != -1? dp[index+1][index+1]: solve(nums, index+1, index,k, dp)+nums[index];
        }
        
        nottake = dp[index+1][prev_index+1]!=-1? dp[index+1][prev_index+1]: solve(nums, index+1, prev_index, k, dp);
        
        return dp[index][prev_index+1] =  max(take, nottake);
        
    } 
    int constrainedSubsetSum(vector<int>& nums, int k) {
		    priority_queue<array<int, 2>> que;
		    int ret = nums[0], curr;
		    que.push({nums[0], 0});
		    for (int i = 1; i < nums.size(); i++) {
		    while (!que.empty() && que.top()[1] < i - k) {
		    que.pop();
		    }
		    curr = max(0, que.top()[0]) + nums[i];
		    ret = max(ret, curr);
		    que.push({curr, i});
		    }
		    return ret;

//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
//         int ans = solve(nums, 0, -1, k, dp), maxx=INT_MIN+1;
        
//         if(ans!=0)
//         return ans;

//         for(int i=0; i<nums.size(); i++)
//             maxx=max(maxx, nums[i]);
        

//          return maxx;
    }
};