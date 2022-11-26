class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        // for(auto it: nums) cout<<it<<" "; cout<<endl;
        ans.push_back(nums[0]);
        // for(auto it: ans) cout<<it<<" "; cout<<endl;
            
        int len = 1;
        for(int i=1; i<n; i++)
        {
            
            if(nums[i]>ans.back()) {
                ans.push_back(nums[i]);
                len++;
            }
            else{
                int it = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[it] = nums[i];
            }
            // for(auto it: ans) cout<<it<<" "; cout<<endl;
            
        }
        
        
        return len;
    }
};