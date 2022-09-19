class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int > res(n);

        // firtsly we can multiply the left part of the array 
        int temp = 1;
        for( int i = 0 ; i< n  ;i++ )
        {
            res[i]= temp ;
            temp =  temp * nums[i];
        }

        // then we have to multiply the right half including left array 
         temp = 1 ;
        for( int i = n -1  ; i >= 0 ; i--){
            res[i] *= temp ;
            temp = temp * nums[i];
        }

        return res;
    }
};