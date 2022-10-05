class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using piv = pair<int, vector<int>>;
        priority_queue<piv> pq;
        
        for(auto it: points)
        {
            pq.push({(pow(it[0],2)+pow(it[1],2)), it});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> out;
        
        while(!pq.empty())
        {
            out.push_back(pq.top().second); pq.pop();
        }
        return out;
    }
};