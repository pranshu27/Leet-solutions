class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        int n = nums.size();
        int i = n-1;
        
        while(i>=1){
            if(nums[i-1]>=nums[i]){
                i--;
            }
            else break;
        }
        if(i==0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        i--;
        // find next greater
        int ng = INT_MAX, ngi = -1;
        int j = i+1;
        while(j<n){
            if(nums[j]>nums[i] && nums[j]<=ng){
                ng = nums[j];
                ngi = j;
            }
            j++;
        }
        //cout<<ng<<" "<<ngi<<endl;
        //cout<<i<<endl;
        
        swap(nums[i], nums[ngi]);
        
        for(int k=i+1, j = n-1; k<n && k<j; k++, j--)
        {
            swap(nums[k], nums[j]);
        }
    }
};