class Solution {
public:
    int sides[4];
    bool dfs(vector<int>& arr, int index, int n, int req){
        if(index==n){
            if( sides[0] == sides[1] && sides[1] == sides[2] &&sides[2] == sides[3])
            {
                return true;
            }
            return false;
        }
        
        for(int i=0; i<4; i++){
            
            if(sides[i] + arr[index]>req) continue;
            
            sides[i]+= arr[index];
            if(dfs(arr, index+1, n, req)) return true;
            sides[i]-= arr[index];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        memset(sides, 0, sizeof(sides));
       // return dfs(arr, 0, arr.size());
        int s = 0;
        for(auto it:arr) s+=it;
        if(arr.size()<4 || s%4) return false;
        
        int req = s/4;
        return dfs(arr, 0, arr.size(), req);
    }
};