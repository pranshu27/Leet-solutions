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
        
//         for(auto it:x) cout<<it<<" ";
//         cout<<endl;
//         for(auto it:pre) cout<<it<<" ";
//         cout<<endl;
        
        int maxx = 1;
        int start = 0, end = 1;
//         while(end<n)
//         {
//             int a = start>0? pre[end]-pre[start-1]: pre[end];
//             int b = start>0? x[end]^x[start-1]: x[end];
            
                
            // if(a==b){
            //     maxx = max(maxx, end-start+1);
            // }
//             else 
//             {
//                 while(a!=b)
//                 {
//                     start++;
//                     a = start>0? pre[end]-pre[start-1]: pre[end];
//                     b = start>0? x[end]-x[start-1]: x[end];
//                 }
//             }
//             end++;
//         }
        
        for(int i=0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                long long a = i>0? pre[j]-pre[i-1]: pre[j];
                long long b = i>0? x[j]^x[i-1]: x[j];
                    if(a==b){
                    maxx = max(maxx, j-i+1);
                }
                else break;
                
            }
        }
        
        return maxx;
        
    }
};