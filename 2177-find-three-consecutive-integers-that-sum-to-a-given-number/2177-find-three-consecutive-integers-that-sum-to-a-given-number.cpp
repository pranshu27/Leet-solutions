class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>a;long long s=num/3;
        if(num%3!=0)
            return a;
        a.push_back(s-1);
        a.push_back(s);
        a.push_back(s+1);
        return a;
    }
};