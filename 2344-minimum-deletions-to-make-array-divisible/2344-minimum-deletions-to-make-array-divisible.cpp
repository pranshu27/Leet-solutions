class Solution {
public:
    int findGCD(int a, int b) //Euclids GCD algo
    {
        if(b==0) return a;
        return findGCD(b, a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int c = 0;
        sort(begin(nums), end(nums));
        int op = numsDivide[0];
        int n = numsDivide.size();
        for(int i = 1;i < n;i++){
            op = (op>numsDivide[i])? findGCD(op,numsDivide[i]): findGCD(numsDivide[i], op); 
        }
        for (int i = 0; i < nums.size(); ++i)
            if (op % nums[i] == 0)
                return i;
        return -1;
    }
};