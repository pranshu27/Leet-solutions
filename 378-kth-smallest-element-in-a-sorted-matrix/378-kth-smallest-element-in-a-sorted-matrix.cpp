class Solution {
public:
    int kthSmallest(vector<vector<int>>& arr, int k) {
        priority_queue<int> pq;
        int m = arr.size(), n = arr[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                pq.push(arr[i][j]);
                if(pq.size()>k) pq.pop();
            }
        }
        
        return pq.top();
        
    }
};