class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> m;
        
        int res = 0;
        int left, right;
        for(int &i:nums){
            if(m.find(i)==m.end()){ //to avoid duplicates
                left = m.find(i-1)!=m.end()?m[i-1]:0;
                right = m.find(i+1)!=m.end()?m[i+1]:0;

                res = max(res, left + right + 1);

                m[i] = left + right + 1;
                
                //reflect the corresponding changes to the boundaries
                m[i-left] = left + right + 1; 
                m[i+right] = left + right + 1;
            }
            
        }
        
        return res;
    }
};