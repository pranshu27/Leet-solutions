class Solution {
public:
    
    int longestCycle(vector<int>& edges) {
          int n = edges.size(), mx = 0;
        vector<vector<int>> graph(n), reverse_graph(n);
        
        for(int i = 0; i < n; i++)
            if(edges[i] >= 0)
                graph[i].push_back(edges[i]), reverse_graph[edges[i]].push_back(i);   

        stack<int> st;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++)
            if(!visited[i])
                dfs1(graph, st, i, visited);   
        
        for(int i = 0; i < n; i++)
            visited[i] = false;
              
        while(!st.empty())
        {
            int tmp = 0;
            if(!visited[st.top()])
                dfs2(reverse_graph, st.top(), visited, tmp), mx = max(mx, tmp);    
        
            st.pop();
        }
        
        return mx <= 1 ? -1 : mx;
    }
    
    void dfs1(vector<vector<int>> &graph, stack<int> &st, int i, vector<bool> &visited)
    {        
        visited[i] = true;
        for(auto &j : graph[i])
            if(!visited[j])
                dfs1(graph, st, j, visited);
        
        st.push(i);
    }
    
    void dfs2(vector<vector<int>> &graph, int i, vector<bool> &visited, int &tmp)
    {
        visited[i] = true, tmp++;
        for(auto &j : graph[i])
            if(!visited[j])
                dfs2(graph, j, visited, tmp);
    }
};