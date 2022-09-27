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
        string k1=to_string(i1+1)+"."+to_string(j1)+"."+to_string(i2+1)+"."+to_string(j2);
        string k2=to_string(i1+1)+"."+to_string(j1)+"."+to_string(i2)+"."+to_string(j2+1);
        string k3=to_string(i1)+"."+to_string(j1+1)+"."+to_string(i2+1)+"."+to_string(j2);
        string k4=to_string(i1)+"."+to_string(j1+1)+"."+to_string(i2)+"."+to_string(j2+1);
        
        if(i1==i2&&j1==j2)temp=grid[i1][j1];
        else temp=grid[i1][j1]+grid[i2][j2];
        int x1=p.count(k1)==0? solve(i1+1,j1,i2+1,j2,grid): p[k1];
        int x2=p.count(k2)==0?solve(i1+1,j1,i2,j2+1,grid): p[k2];
        int x3=p.count(k3)==0?solve(i1,j1+1,i2+1,j2,grid): p[k3];
        int x4=p.count(k4)==0?solve(i1,j1+1,i2,j2+1,grid): p[k4];
        
        return p[mp]=temp+max({x1,x2,x3,x4});
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size(); 
        int z= solve(0,0,0,0,grid); 
        if(z<-1e4)return 0;
        else return z;
    }
};