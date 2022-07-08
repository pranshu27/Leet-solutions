class Solution {
public:
    int dp[101][21][101];
    int solve(vector<int>& houses, vector<vector<int>>& cost, int prev, int target, int index){
        
        if(index==houses.size() || target < 0){
            return target==0? target: 1000001;
        }
        
        if(dp[index][prev][target]!= -1) return dp[index][prev][target];
        
        //
        if(houses[index]!=0) 
            return solve(houses, cost, houses[index], target - (prev!=houses[index]), index+1);
        
        int minn = 1000001;
        for(int i=1; i<=cost[index].size(); i++){
            minn = min(minn, cost[index][i-1] + solve(houses, cost, i, target - (prev!=i), index+1));           
        }
        
        return dp[index][prev][target] = minn;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        memset(dp, -1, sizeof(dp));
        int res = solve(houses, cost, 0, target, 0);
        return res>1000000? -1: res;
    }
};