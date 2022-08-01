class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxx = 0, minn = INT_MAX;

        for(const int &it: prices)
        {
            maxx = max(maxx, it - minn);
            minn = min(minn, it);
        }
        
        return maxx;
    }
};