class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> x(n), pre(n);
        x[0] = pre[0] = nums[0];
        for(int i = 1; i<n; i++)
        {
            pre[i]=pre[i-1]+nums[i];
            x[i]=x[i-1]^nums[i];
        }
        
        int maxx = 1;
        int start = 0, end = 1;
//    
        for(int i=0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                long long a = i>0? (pre[j]-pre[i-1]): pre[j];
                long long b = i>0? (x[j]^x[i-1]): x[j];
                if(a==b){
                    maxx = max(maxx, j-i+1);
                }
                else break;
                
            }
        }
        
        return maxx;
        
    }
};