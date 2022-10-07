class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long n = nums.size();
        for(int i=0; i<n; i++)
        {
            nums[i] = i - nums[i];
        }
        
        unordered_map<long long, long long> mp;
        for(auto &it: nums){
            mp[it]++;
        }
        
        long long tot;
        if(n%2)
            tot = n*((n-1)/2);
        
        else
            tot = (n/2)*(n-1);
            
        
        for(auto [l,r]: mp)
        {
            if(r%2)
                tot -= r*((r-1)/2);

            else
                tot -= (r/2)*(r-1);
            
            // tot -= r*(r-1)/2;
        }
        
        return tot;
    }
};