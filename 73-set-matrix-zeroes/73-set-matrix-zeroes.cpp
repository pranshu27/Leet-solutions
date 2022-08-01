class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeros;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!matrix[i][j]){
                    zeros.push_back({i, j});
                }
            }
        }
        
        for(auto &[i, j]: zeros){
            matrix[i] = vector<int>(n, 0);
            for(int k = 0; k<m; k++) matrix[k][j] = 0;
        }
        
    }
};