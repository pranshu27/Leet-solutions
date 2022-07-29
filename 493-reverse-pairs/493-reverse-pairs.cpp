class Solution {
public:
    int count;
    void merge(vector<int> &v, int l, int r, int mid){
        //vector<int> tmp(r-l+1);
        int k=0;
        int i = l, j=mid+1;
        
        while(i<=mid && j<=r)
        {
            if((long)v[i] > (long)2*v[j])
            {
                count += mid - i + 1;
                j++;
                
            }
            else
            { 
                
                i++;
            }
        }
        
        sort(v.begin()+l, v.begin()+r+1); // we can use standard merge sort code here

        
    }
    void mergeSort(vector<int> &v, int l, int r)
    {
        if(l<r)
        {
            int mid = l + (r-l)/2;
            
            mergeSort(v, l, mid);
            mergeSort(v, mid+1, r);
            merge(v, l, r, mid);
        }
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        count = 0;
        
        mergeSort(nums, 0, n-1);
        return count;
        
    }
};