class Solution {
public:
    int minimumDeletions(string s) {
        int countB = 0;
        
        int del = 0;
        
        for(const char &c: s)
        {
            if(countB && c == 'a') {
                countB--;
                del++;
            }
            else if(c == 'b') countB++;
        }
        
        return del;
        
        
    }
};