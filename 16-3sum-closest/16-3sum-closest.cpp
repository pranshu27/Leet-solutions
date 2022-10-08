class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = INT_MAX, ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(auto it: nums) cout<<it<<" ";
        cout<<endl;
        for(int i=0; i<n-2; i++)
        {
            // if(i+1<n-2 && nums[i]==nums[i+1]) continue;
            int j = i+1, k = n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<=target){
                    j++;
                }
                else k--;
                if(abs(target-sum)<closest){
                    closest = abs(target-sum);
                    ans = sum;
                }
                // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<" "<<sum<<" "                        <<closest<<endl;
            }
            
            // closest = min(closest, abs(target-sum));   
        }
        
        return ans;
    }
};