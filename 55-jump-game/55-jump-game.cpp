class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        
        int jumps = 0, steps = nums[0], maxx = nums[0];
        int n = nums.size();
        if(n==1) return true;
        if(!nums[0]) return false;
        //if(nums.empty() || !nums[n-1]) return false;
        int i = 1;
        while(i<n)
        {
            maxx = max(maxx, i+nums[i]);
            steps--;
            
            if(i==n-1) return true;
            
            if(steps==0)
            {
                jumps++;
                if(maxx<=i) return false;
                steps = maxx-i;
            }
            i++;
        }
        return false;
    }
};