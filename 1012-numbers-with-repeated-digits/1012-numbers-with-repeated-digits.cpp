class Solution {
public:
    int uniqueDigits = 0;
    int numDupDigitsAtMostN(int N) {
        backtrack(0,0, N);
        return N - uniqueDigits + 1; // +1 as 0 is counted
    }
    
    void backtrack(long cur, int bitmask, int& N){
        if(cur > N) return;
        else uniqueDigits++;
        
        for(int digit=0; digit<10; digit++){
            if(bitmask == 0 && digit == 0) continue;
            if((bitmask & (1<<digit)) > 0) continue; // has repeat digits
            backtrack(cur*10 + digit, bitmask | (1<<digit), N);
        }
    }
};