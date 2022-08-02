class Solution {
public:
    int kthSmallest(vector<vector<int>>& arr, int k) {
        using pii = pair<int, int>;
        
        
        auto cmp = [&](pii &a, pii &b){
            return arr[a.first][a.second] > arr[b.first][b.second];
        };
        
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        
        int m = arr.size(), n = arr[0].size();
        
        for(int i=0; i<n; i++)
        {
            pq.push({0, i}); 
        }//pushing the first row
        
        for(int i=0; i<k-1; i++)
        {
            auto [l,r] = pq.top();
            pq.pop();
            
            if(l+1<m) pq.push({l+1, r});
        }
        
        return arr[pq.top().first][pq.top().second];
        
        
    }
};