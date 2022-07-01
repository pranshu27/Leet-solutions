class Solution {
public:
    bool canSplit(vector<int>& nums, int sum, int m)
    {
        int tmp = 0, c = 1;
        
        
        for(int i = 0; i<nums.size(); i++)
        {
            
            tmp+=nums[i];
            if(tmp>sum){
                c++;
                tmp = nums[i];
            }
            if(c>m) return false;
        }
        
        return true;
    }
    int shipWithinDays(vector<int>& nums, int m) {
        int low, high=0;
        for(auto it:nums) {
            low = max(low, it);
            high+=it;
        }
        
        
        while(low<high)
        {
            int mid = low + (high-low)/2;
            
            if(canSplit(nums, mid, m)){
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        
        //cout<<low<<" "<<high<<endl;
        return low;
    }
};