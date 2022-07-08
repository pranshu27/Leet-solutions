
class Solution {
public:
    int gcd(int a, int b){
        if(a==0) return b;
        return gcd(b%a, a);
    }
    
    vector<int> arr{1,2,3,4,5,6};
    
    int dp[10001][10][10];
    long solve(int n, int last, int prevLast, int i) {
        if(i == n)  return dp[i][last+1][prevLast+2] = 1;
        
        if(dp[i][last+1][prevLast+2]!=-1) return dp[i][last+1][prevLast+2];
        
        long res = 0;
        for(int &j:arr) {
            if(j == last || j == prevLast || (last!=-1 && (gcd(j, last)!=1))) continue;
            res+=solve(n, j, last, i+1);
            res%=1000000007;
        }
        return dp[i][last+1][prevLast+2] = res;
    }
    
    int distinctSequences(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, -1, -1, 0);   
    }
};