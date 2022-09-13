class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;;
        if(arr[0]==0) return -1;
        
        int mr = arr[0], jumps = 1, steps = arr[0];
        
        
        for(int i=1; i<n; i++)
        {
            if(i==n-1) return jumps;
            
            mr = max(mr, arr[i]+i);
            
            steps--;
            
            if(steps==0)
            {
                jumps++;
                if(mr<=i) return -1;
                steps = mr-i;
            }
        }
        
        return -1;
    }
};