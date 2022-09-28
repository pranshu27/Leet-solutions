class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();


        
        int maxx = 1;
        
        
        for(int i=0; i<n; i++)
        {
            int len = 1;
            int tmp = nums[i];
            for(int j = i; j<n-1; j++)
            {
                if((tmp^nums[j+1]) == (tmp+nums[j+1]))
                {
                    tmp = tmp+nums[j+1];
                    len++;
                }
                
                else break;
            }
            maxx = max(len, maxx);
        }
        
        return maxx;
        
    }
};