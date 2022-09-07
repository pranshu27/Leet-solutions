class Solution {
public:
    int maxi = INT_MAX/4;
    // vector<int> par;
    vector<int> dis;
    vector<bool> vis;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // par.resize(n, -1);
        dis.resize(n, maxi);
        vis.resize(n, false);
        dis[0] = 0;
        
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0});
        
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            if(vis[u]) continue;
            vis[u] = true;
            for(int i = 0; i < n; i++){
                int wt = abs(points[i][0] - points[u][0]) + abs(points[i][1] - points[u][1]); 
                if(i != u && vis[i] == false && dis[i] > wt){
                    dis[i] = wt;
                    pq.push({dis[i], i});
                }
            }
        }
        
        int sum = 0;
        for(auto it: dis) sum+=it;
        return sum;
        
    }
};