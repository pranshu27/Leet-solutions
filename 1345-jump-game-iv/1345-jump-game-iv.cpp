class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        
        int n = arr.size();
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]].push_back(i);
        }
        
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        
        
        int steps = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--){
                int i = q.front();
                q.pop();
                
                
                
                if(i==n-1) return steps;
                
                vector<int> &jumps = mp[arr[i]];
                jumps.push_back(i-1);
                jumps.push_back(i+1);
                
                for(int &k: jumps){
                    if(k>0 && k<n && visited[k]==0){
                        visited[k] = 1;
                        q.push(k);
                    }
                }
                jumps.clear();
            }
            steps++;
        }
        
        return -1;
    }
};