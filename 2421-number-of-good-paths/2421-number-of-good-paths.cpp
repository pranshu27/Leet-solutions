class Solution {
public:
    
    vector<int> parent, rank;
    
    int findPar(int n)
    {
        if(parent[n] == n) return n;
        return parent[n] = findPar(parent[n]);
    }
    
    void unionn(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[v] < rank[u]) {
            parent[v] = u; 
        }
        else {
            parent[v] = u;
            rank[u]++; 
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n); 
        rank.resize(n);
        // for()
        map<int, vector<int>> mp;
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
            mp[vals[i]].push_back(i);
        }
        
        unordered_map<int, vector<int>> adj;
        
        for(auto it: edges){
            int node1 = it[0];
            int node2 = it[1];
            
            if(vals[node1]>=vals[node2]) adj[node1].push_back(node2);
            if(vals[node2]>=vals[node1]) adj[node2].push_back(node1);
        }
        
        // for(auto it: adj){
        //     cout<<it.first<<" ";
        //     for(auto x: it.second) cout<<x<<" "; cout<<endl;
        // }
        int ans = 0;
        for(auto [value,indexes]: mp)
        {
            for(auto it: indexes){
                for(auto it1: adj[it]) unionn(it, it1);
            }
            unordered_map<int, int> count;
        
            for(auto it: indexes)
            {
                count[findPar(it)]++;
            }
            
            ans += indexes.size();
            
            for(auto [l,r]: count){
                if(r>1) ans+=r*(r-1)/2;
            }
        }

        return ans;
    }
};