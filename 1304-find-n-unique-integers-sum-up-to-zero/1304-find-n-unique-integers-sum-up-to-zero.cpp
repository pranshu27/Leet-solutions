class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> out;
        for(int i=0; i<n/2 + 1; i++)
        {
            if(i==0) {
                if(n%2) out.push_back(i);
                else continue;
            }
            else {
                out.push_back(i);
                out.push_back(-i);
            }
        }
        
        return out;
    }
};