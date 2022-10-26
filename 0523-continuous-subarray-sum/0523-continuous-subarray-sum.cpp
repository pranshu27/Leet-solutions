class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int end = 0, start = 0, sum=0;
        unordered_map<int, int> pre;
        pre[0] = -1;
        
        while(end<n){
            sum+=nums[end];
            
            sum %= k;
            
            if(pre.count(sum)){
                if(end - pre[sum]>1) return true;
            }
            
            else pre[sum] = end;
            end++;
        }
        
        return false;
    }
};