class Solution {
public:
    
    int partition(vector<int> nums, int low, int high){
        int pivot = nums[high];
        int pos = low;
        
        for(int i=low; i<=high; i++){
            if(nums[i]<pivot){
                swap(nums[i], pivot);
                pos++;
            }
        }
        
        swap(nums[pos], nums[high]);
        return pos;
    }
    
    int findMedian(vector<int>& nums,int k, int low, int high)
    {
        int pos = partition(nums, low, high);
        if(pos==k-1) return nums[pos];
        
        if(pos<k-1) return findMedian(nums, k, pos+1, high);
        else return findMedian(nums, k, low, pos-1);
    }
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), sum=0;
        
        if(n==2) return abs(nums[0]-nums[1]);
        
        int median = findMedian(nums, n/2 + 1,0,n-1);
        //cout<<median;
        for (int i=0;i<nums.size();i++) sum += abs(nums[i] - median);
        return sum;

        
    }
};