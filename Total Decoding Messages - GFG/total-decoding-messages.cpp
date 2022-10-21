//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int mod;
	   // unordered_map<string, int> mp;
	   vector<int> v;
	    int solve(int p, string &s)
	    {
	        
	        int n = s.size();
            if(p == n) return 1;
            if(s[p] == '0') return 0; 
            
            if(v[p]!=-1) return v[p];
            int res = solve(p+1,s);
            if( p < n-1 && (s[p]=='1'|| (s[p]=='2'&& s[p+1]<'7'))) res += solve(p+2,s);
            return v[p] = res%mod;
	    }
		int CountWays(string str){
		    if(str.length()==1 && str[0]=='0') return 0;
		    mod = 1e9+7;
		    for(int i=0; i<str.length()-1; i++){
		        if(str[i]==0 && str[i]==str[i+1]) return 0;
		    }
		    v.resize(str.length()+1, -1);
		    return solve(0, str);
		    // Code here
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends