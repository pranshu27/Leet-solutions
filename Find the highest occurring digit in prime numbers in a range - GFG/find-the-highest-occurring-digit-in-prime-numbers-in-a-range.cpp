//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    vector<bool> primes;
    
    void build()
    {
        primes[0] = primes[1] = false;
        for(int i=2; i*i<=1000; i++)
        {
            if(primes[i])
            {
                for(int p = i*i; p<=1000; p+=i) primes[p] = false;
            }
        }
    }
    int maxDigit(int L, int R)  {
        // code here
        primes.resize(1001, true);
        unordered_map<int, int> mp;
        build();
        
        // for(auto it:primes) cout<<it<<endl;
        int out, maxx = 0;
        for(int i = L; i<=R; i++) {
            if(primes[i]){
                // cout<<i<<" ";
                int j = i;
                while(j)
                {
                    int dig = j%10;
                    mp[dig]++;
                    if(mp[dig]>=maxx){
                        maxx = mp[dig];
                        out = dig;
                    }
                    j = j/10;
                }
            }
        }
        
        // for(auto it: mp) cout<<it.first<<" "<<it.second<<endl;
        
        return maxx? out: -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        cout<<ob.maxDigit(L,R)<<endl;
    }
    return 0;
}

// } Driver Code Ends