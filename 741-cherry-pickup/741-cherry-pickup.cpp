class Solution {
public:
    int m; 
    unordered_map<string ,int>p;
    int solve(int i1,int j1,int i2,int j2,vector<vector<int>>& grid)
    {
        if(i1>=m||i2>=m||j1>=m||j2>=m||grid[i1][j1]==-1||grid[i2][j2]==-1)
            return -1e5;
        
        if(i1==m-1&&j1==m-1)
            return grid[i1][j1];
            
        
        int temp=0; 
    string mp=to_string(i1)+"."+to_string(j1)+"."+to_string(i2)+"."+to_string(j2);
        if(p.count(mp)!=0)return p[mp];
        
        if(i1==i2&&j1==j2)temp=grid[i1][j1];
        else temp=grid[i1][j1]+grid[i2][j2];
        int x1=solve(i1+1,j1,i2+1,j2,grid);
        int x2=solve(i1+1,j1,i2,j2+1,grid);
        int x3=solve(i1,j1+1,i2+1,j2,grid);
        int x4=solve(i1,j1+1,i2,j2+1,grid);
        
        return p[mp]=temp+max({x1,x2,x3,x4});
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size(); 
        int z= solve(0,0,0,0,grid); 
        if(z<-1e4)return 0;
        else return z;
    }
};