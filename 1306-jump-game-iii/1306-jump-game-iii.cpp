class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<pair<int, int>> q{{{start, arr[start]}}};
        vector<int> vis(n, 0);
        vis[start] = 1;
        while(!q.empty()){
            pair<int, int> pr = q.front();
            q.pop();
            if(pr.second == 0){
                return true;
            }
			// Addition :- i + arr[i]
            int pos1 = pr.first + pr.second;
            if(pos1 < n && !vis[pos1]){
                q.push({pos1, arr[pos1]});
                vis[pos1] = 1;
            }
			// Substraction :- i - arr[i]
            int pos2 = pr.first - pr.second;
            if(pos2 >= 0 && !vis[pos2]){
                q.push({pos2, arr[pos2]});
                vis[pos2] = 1;
            }
        }
        return false;
    }
};