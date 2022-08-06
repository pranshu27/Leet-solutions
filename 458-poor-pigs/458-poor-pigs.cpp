class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // thh base case is if we have t tests, and 1 pig, we can detect t+1 buckets
        //(t+1)^p>=buckets;
        
        int tests=minutesToTest/minutesToDie;
        return ceil(log2(buckets)/log2(tests+1));
        
    }
};