class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<int> adj[n+1];
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<pair<int, int>> v(n+1, {0,0});
        queue<pair<int, int>> q;
        
        q.push({1, 0}); // pehla no hai, doosra visited time
        v[1] = {1, 0};
        while(!q.empty())
        {
            auto [node, t] = q.front();
            q.pop();
            
            bool needWait = (t/change%2==1);
            int wait;
            if(needWait) wait = (t/change + 1)*change - t;
            else wait = 0;
            
            int next = t+wait+time;
            
            for(auto &it: adj[node])
            {
                if(v[it].first<2 && v[it].second!=next){
                    q.push({it,  next});
                    (v[it].first)+=1;
                    v[it].second = next;
                   
                    
                    if(it==n && v[it].first == 2) return next;
                }
                
            }
        }
        
        return -1;
    }
};