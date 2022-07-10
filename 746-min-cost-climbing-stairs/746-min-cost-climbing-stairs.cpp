class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        
        //if(cost.size()==1) return cost[0];
        //if(cost.size()==2) return min(cost[0], cost[1]);
        
        dp[0] = dp[1] = 0;
        
        for(int i=2; i<cost.size(); i++){
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        
        return min(dp[n-1]+cost[n-1], dp[n-2]+cost[n-2]);
        
    }
};