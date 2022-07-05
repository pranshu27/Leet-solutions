class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3) return  vector<long long>{};
        
        
        long long  x = num/3;
        return vector<long long>{x-1,x,x+1};
    }
};