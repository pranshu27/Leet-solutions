// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int dp[81];
    long long int solve(int n){
        if(n<=3) return  dp[n] = 1;
        
        if(dp[n]!=-1) return dp[n];
        return dp[n] = solve(n-1) + solve(n-4);
    }
    long long int arrangeTiles(int N){
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(N);
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends