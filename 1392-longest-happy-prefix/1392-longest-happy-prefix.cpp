class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
	    vector<int> lps(n, 0);
        // int maxx = 0;
	    
	    int len = 0, i = 1;
	    
	    while(i<n){
	        if(s[len] == s[i]){
	            len++;
	            lps[i] = len;
	            i++;
	        }
	        else{
	            if(len!=0){
	                len = lps[len-1];
	            }
	            else{
	                lps[i] = 0;
	                i++;
	            }
	        }
	    }
	    
	    return s.substr(0, lps[n-1]);
        
    }
};