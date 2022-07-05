class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        
        int res = 0;
        for(int i:nums){
            if(m.find(i)==m.end()){
                int left = m.find(i-1)!=m.end()?m[i-1]:0;
                int right = m.find(i+1)!=m.end()?m[i+1]:0;

                res = max(res, left + right + 1);

                m[i] = left + right + 1;

                m[i-left] = left + right + 1;
                m[i+right] = left + right + 1;
            }
            
        }
        
        return res;
    }
};