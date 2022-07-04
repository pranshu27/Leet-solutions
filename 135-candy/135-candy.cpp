class Solution {
public:
    int candy(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> out(n, 1);
        
        int j, curr;
        int sum = 0;
        for(int i=0; i<n-1;)
        {
            if(i+1<n && arr[i+1]>arr[i]) {
                out[i+1] = out[i]+1;
                i++;
            }
            else if(i+1<n && arr[i+1]<arr[i])
            {
                j = i;
                while(j+1<n && arr[j+1]<arr[j]) j++;
                curr = j-i+1;
                out[i] = max(out[i], curr); 
                j = i+1;
                while(j+1<n && arr[j+1]<arr[j]) {
                    out[j] = --curr;
                    j++;
                }
                i=j;
            }
            else {
                i++;
            }

        }
        for(int it: out) sum+=it;
        return sum;
    }
};