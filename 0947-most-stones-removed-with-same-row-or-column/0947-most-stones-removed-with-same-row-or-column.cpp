class Solution {
public:
    
    vector<int> parent, sz;
    
    int findPar(int a)
    {
        if(a == parent[a]) return a;
        return parent[a] = findPar(parent[a]);
    }
    
    bool unionn(int a, int b)
    {
        a = findPar(a);
        b = findPar(b);
        
        if(a==b) return false;
        
        if(sz[a]>sz[b]) {
            parent[b]=a;
            sz[a]+=sz[b];
        }
        else{
            parent[a]=b;
            sz[b]+=sz[a];
        }
        
        return true;
        
    }
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        
        parent.resize(n);
        sz.resize(n);
        
        
        for(int i=0; i<n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
        
        int count = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                   {
                       if(unionn(i, j)) count++;
                   }
            }
        }
               
        // for(auto it: parent) cout<<it<<" "; cout<<endl;
        // for(auto it: sz) cout<<it<<" "; cout<<endl;
        
        return count;
    }
};