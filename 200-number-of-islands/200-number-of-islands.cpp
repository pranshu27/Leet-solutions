class Solution {
    public:
    void change(vector<vector<char>>& grid,int x,int y)
       {
           grid[x][y] = '0';
           int dx[] = {0,0,1,-1};
           int dy[] = {1,-1,0,0};
           for(int i = 0; i < 4; i++)
           {
               int cx = x + dx[i];
               int cy = y + dy[i];
               if(cx >= 0 && cx < grid.size() && cy < grid[0].size() && cy >= 0 && grid[cx][cy] == '1')
               change(grid,cx,cy);
           }
       }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
       int m = grid[0].size();
       int count = 0;
       for(int i = 0; i < n; i++)
       {
           for(int j = 0; j < m; j++)
           {
               if(grid[i][j] == '1')
               {
                   change(grid,i,j);
                   count++;
               }
           }
       }
       return count;
    }
};