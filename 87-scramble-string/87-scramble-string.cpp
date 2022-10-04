class Solution {
public:
    unordered_map<string, bool> mp;
    
    
    bool solve(string a, string b){
        if(a==b) return true;
        if(a.length()!=b.length()) return false;
        if(a.length()<1) return false;
        
        string key = a+b;
        if(mp.find(key)!=mp.end()) return mp[key];
        
        
        int n = a.length();
        // bool flag = false;
        
        for(int i=1; i<=n-1; i++)
        {
            bool swapped = (
            solve(a.substr(0, i), b.substr(n-i, i)) &&
                solve(a.substr(i, n-i), b.substr(0, n-i))
            );
            
            bool not_swapped = (
            solve(a.substr(0, i), b.substr(0, i)) &&
                solve(a.substr(i, n-i), b.substr(i, n-i))
            );
            
            if(swapped || not_swapped) {
               return  mp[key] = true;
            }
            
        }
        
        return  mp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};