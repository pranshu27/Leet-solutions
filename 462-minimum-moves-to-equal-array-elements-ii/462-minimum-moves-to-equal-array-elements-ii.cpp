class Solution {
public:
    int partition(vector<int>& nums, int l, int h)
    {
        int num = (l+h)/2;
        swap(nums[h], nums[num]);
        int i=l,j,pi=h;
        for(j=l; j<h; j++)
        {
            if(nums[j]<nums[pi])
            {
                
                swap(nums[i], nums[j]);
                i++;
            }
        }
        
        swap(nums[i], nums[pi]);
        return i;
    }
    
    int quick(vector<int>& nums, int l, int h, int find)
    {
        if(l<=h)
        {
            int pi = partition(nums, l, h);
            
            if(pi==find)
            {
               
                return nums[pi];
            }
            
            if(pi>=find)
                return quick(nums, l, pi-1, find);
            
            else
                return quick(nums, pi+1, h, find);
        }
        
        return -1;
    }
    

    
    int minMoves2(vector<int>& nums) {
        
        
        int n = nums.size(), sum=0;
        
        
        int median = quick(nums,0,n-1,n/2);
        for (int i=0;i<nums.size();i++) sum += abs(nums[i] - median);
        return sum;

        
    }
};