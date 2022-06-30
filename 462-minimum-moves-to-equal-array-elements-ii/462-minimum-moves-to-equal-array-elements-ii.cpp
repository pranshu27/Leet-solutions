class Solution {
public:
    
    long long findDiff(vector<int> nums, long long i)
    {
        long long sum = 0;
        for(auto it: nums)
        {
            if(it == i) continue;
            else sum+=abs(it-i);
        }
        return sum;
    }
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        if(n==2) return abs(nums[0]-nums[1]);
        
        if(n%2){
            return findDiff(nums, nums[n/2]);
        }
       
        return min({
            findDiff(nums, nums[n/2]), findDiff(nums, nums[n/2 + 1])
        });
       
        
    }
};