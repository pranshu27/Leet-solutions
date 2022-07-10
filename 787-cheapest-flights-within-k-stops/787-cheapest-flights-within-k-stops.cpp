typedef tuple<int,int,int> ti;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        
        for(vector<int> &v: flights)
        {
            adj[v[0]].push_back({v[1], v[2]});
        }
        
        priority_queue<ti,vector<ti>,greater<ti>>pq;
        pq.push({0, src, 0});
        
        
        vector<int> s(n, 102); // extra array used for storing stops
        
        while(!pq.empty()){
            auto [cost,u,stops] = pq.top();
            pq.pop();
            if(u==dst)  return cost;
            
            if(stops<s[u] && stops<=k){
                s[u] = stops;
                for(auto to:adj[u]){
                    auto [v,w] = to;
                    pq.push({cost+w,v,stops+1});
                    //cout<<cost+w<<" "<<v<<" "<<stops+1<<endl;
                }
            }
            for(auto it:s) cout<<it<<" "; cout<<endl;
            
        }
        return -1;
    }
};