class Solution {
public:
    int dp[1005];
    int solve(int i, int j, vector<int> nums)
    {
        if(i>=nums.size()) return 0;
        
        if(dp[j+1] != -1) return dp[j+1];
        
        int take = 0, nottake =  solve(i+1, j, nums);
        if(j==-1 || (nums[j]<0 && nums[i]>=0) || (nums[j]>=0 && nums[i]<=0))
            take = 1 + solve(i+1, i, nums);
        
        return dp[j+1] = max(take, nottake);
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1) return 1;

        vector<int> diff;
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]-nums[i] != 0)
                diff.push_back(nums[i+1]-nums[i]);
        }
        
        
        memset(dp, -1, sizeof(dp));
        return 1+solve(0,-1,diff);
        
        
    }
};