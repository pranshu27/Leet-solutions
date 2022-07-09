class Solution {
public:

    int maxResult(vector<int>& nums, int k) {
        
        
        priority_queue<pair<int, int>> pq;
        
        int n = nums.size();
        int score;
        for(int i = n-1; i>=0; i--)
        {
            while(pq.size() && pq.top().second > i+k) pq.pop();
            score = nums[i];
            score += pq.size()? pq.top().first: 0;
            pq.push({score, i});
        }
        
        return score;
    }
    
};