class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int sum=0;
        for(int i=0; i<32; i++)
        {
            int zeros = 0, ones = 0;
            for(auto it: nums)
            {
                if(it&(1<<i)) ones++;
                else zeros++;
            }
            sum+=ones*zeros;
        }
        
        return sum;
        
    }
};