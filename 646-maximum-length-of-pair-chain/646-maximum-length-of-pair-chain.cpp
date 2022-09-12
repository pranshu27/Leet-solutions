class Solution {
public:
    
    static bool comp(vector<int> a, vector<int> b)
    {
        return a[1]<b[1];
    }
    int dp[1001][1001];
    int solve(int i, int j, vector<vector<int>>& pairs, int n)
    {
        if(i==n || j==n || i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take=0, nottake=0;
        if(pairs[i][1] < pairs[j][0])
        {
            
            take = 1+ ((dp[j][j+1]==-1)? solve(j, j+1, pairs, n): dp[j][j+1]);
        }
        nottake = (dp[i][j+1]==-1)? solve(i, j+1, pairs, n): dp[i][j+1];
        return dp[i][j] = max(take, nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        memset(dp, -1, sizeof(dp));
        //for(auto a:pairs) cout<<a[0]<<" "<<a[1]<<endl;
        int n = pairs.size();
        return 1+solve(0, 1,pairs, n);
    }
};