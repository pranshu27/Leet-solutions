class Solution {
public:
    

    int minimumEffort(vector<vector<int>>& t) {
        

        sort(t.begin(), t.end(), [](vector<int> &t1, vector<int> &t2) 
         { return t1[1] - t1[0] > t2[1] - t2[0]; });
            
        int energy = 0, ans = 0;
        for(vector<int> it: t)
        {
            ans += max(0, it[1] - energy);
            energy = max(energy, it[1]) - it[0];
        }
        
        return ans;
        
    }
};