class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];
        
        int i=0, j=1, mid, count;
        
        while(low<high)
        {
            mid = (low+high)>>1;
            count = 0;
            int i=0, j=1; 
            while(i<n){
                while(j<n && nums[j]-nums[i]<=mid)
                {
                    j++;
                }
                count = count + j-i-1;
                i++;
            }
            
            if(count<k) low = mid+1;
            else high = mid;
        }

        return low;
    }
};