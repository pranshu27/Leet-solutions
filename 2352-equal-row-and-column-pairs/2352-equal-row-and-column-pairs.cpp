class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        
        for(int i=0; i<grid.size(); i++){
            mp[grid[i]]++;
        }
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> trans(n, vector<int>(m, -1));
        
        for(int i=0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                trans[j][i] = grid[i][j];
            }
        }
        
        int count = 0;
        for(int i=0; i<trans.size(); i++){
            count+=mp[trans[i]];
        }
        
        return count;
    }
};