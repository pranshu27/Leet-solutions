class Solution {
public:
    
    int findFirst(vector<int>& nums, int target){
        
        int index = -1;
        
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(nums[mid]>target) high = mid-1;
            else if(nums[mid]<target) low = mid+1;
            else {
                index = mid;
                high = mid-1;
            }
            
        }
        return index;
    }
     int findLast(vector<int>& nums, int target){
        
        int index = -1;
        
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(nums[mid]>target) high = mid-1;
            else if(nums[mid]<target) low = mid+1;
            else {
                index = mid;
                low = mid+1;
            } 
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {
            findFirst(nums, target),
            findLast(nums, target),
        };
    }
};