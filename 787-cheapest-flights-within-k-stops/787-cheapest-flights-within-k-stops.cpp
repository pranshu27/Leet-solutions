class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //int n = flights.size();
        vector<pair<int, int>> adj[n];
        
        for(vector<int> &v: flights)
        {
            adj[v[0]].push_back({v[1], v[2]});
        }
        
        using vi = vector<int>; // {cost, source, stops }
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        
        pq.push({0, src, 0});
        
        vector<int> s(n, 102);
        
        while(!pq.empty())
        {
            auto it = pq.top();
            int node = it[1];
            int cost = it[0];
            int stops = it[2];
            pq.pop();
            
            if(node==dst) return cost;

            if(stops<s[node] && stops<=k)
            {
                s[node] = stops;
                for(auto it: adj[node]){
                    pq.push({cost+it.second, it.first, stops+1});
                }
            }
        }
        
        return -1;
    }
};