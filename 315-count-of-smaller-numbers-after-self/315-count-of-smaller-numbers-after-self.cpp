class Solution {
public:
    void merge(vector<pair<int, int>> &v, int l, int r, int mid,  vector<int> &out){
        vector<pair<int, int>> tmp(r-l+1);
        int k=0;
        int i = l, j=mid+1;
        
        while(i<=mid && j<=r)
        {
            if(v[i].first <= v[j].first)
            {
                tmp[k++] = v[j++];
                
            }
            else
            { 
                out[v[i].second]+= r-j+1;
                tmp[k++] = v[i++];
            }
        }
        
        while(i<=mid) tmp[k++] = v[i++];
        while(j<=r) tmp[k++] = v[j++];
        
        for(int i = l; i<=r; i++)
        {
            v[i] = tmp[i - l];
        }
        
    }
    void mergeSort(vector<pair<int, int>> &v, int l, int r, vector<int> &out)
    {
        if(l<r)
        {
            int mid = l + (r-l)/2;
            
            mergeSort(v, l, mid, out);
            mergeSort(v, mid+1, r, out);
            merge(v, l, r, mid, out);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        vector<int> out(n, 0);
        
        for(int i=0; i<nums.size(); i++)
        {
            v[i] = {nums[i], i};
        }
        
        mergeSort(v, 0, n-1, out);
        return out;
    }
};