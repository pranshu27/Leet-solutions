class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& arr, int target) {
        
        unordered_map<int, int> mp;
        
        int m = arr.size();
        int n = arr[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                arr[i][j]+=arr[i][j-1];
            }
        }
        
        int count = 0;
        for(int start = 0; start<n; start ++)
        {
            for(int end = start; end<n; end++)
            {
                mp.clear();
                int sum = 0;
                
                
                for(int i=0; i<m; i++)
                {
                    sum += arr[i][end] - ((start>0)? arr[i][start-1]: 0);
                    
                    if(sum == target) count++;
                    
                    count+=mp[sum - target];
                    
                    mp[sum]++;
                }
            }
        }
        
        return count;
    }
};