class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        int count = 0, sum = 0;
        for(auto it: nums)
        {
            sum += it;
            if(sum==k) count++;
            count+=mp[sum-k];
            mp[sum]++;
        }
        
        return count;
    }
};