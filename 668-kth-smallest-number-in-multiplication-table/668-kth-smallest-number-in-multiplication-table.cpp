class Solution {
public:
    
    int countLessThanK(int m, int n, int mid)
    {
        int ans=0;
        for(int i=1; i<=m; i++) ans += min(mid/i, n);
        return ans;
    }
    
    int findKthNumber(int m, int n, int k) {        
        
        int low=1, high = m*n, count; 
        while(low<=high)
        {
            
            int mid = low + (high-low)/2;
            count = countLessThanK(m,n,mid);
            if(count<k) low = mid+1;
            else high = mid-1;
        }
        
        return low;
    }
};