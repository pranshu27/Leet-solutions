class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> curr, ans;
        curr.insert(0);
        for(auto it: arr)
        {
            unordered_set<int> curr2;
            for(auto s: curr)
            {
                curr2.insert(s|it);
            }
            curr2.insert(it);
            curr = curr2;
            for(auto n: curr2) ans.insert(n);
        }
        
        return ans.size();
    }
};