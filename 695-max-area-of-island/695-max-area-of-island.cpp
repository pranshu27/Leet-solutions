class Solution {
public:
    
    
    int dfs(vector<vector<int>>&grid,int i,int j,int n,int m)
    {
	//checking corner cases for moving in 4 direction up down left right
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==1)
        {
            grid[i][j]=0;//updating grid value
            //counting all the island  
            return 1+ dfs(grid,i+1,j,n,m)+
                    dfs(grid,i-1,j,n,m)+
                    dfs(grid,i,j+1,n,m)+
                    dfs(grid,i,j-1,n,m);
            
        }
        return 0;
    }
    
 
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j, m, n);
                    maxx = max(area, maxx);
                }
            }
        }
        return maxx;
    }
};