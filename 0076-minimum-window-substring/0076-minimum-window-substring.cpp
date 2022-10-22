class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n=t.size(), start = 0, end = 0, count = 0, d=INT_MAX;
    
        unordered_map<char, int> mp ;

        string res;

        for(auto x: t)
        {
            mp[x]++;
        }

        count = mp.size();
        
        while(end<m)
        {
            if(--mp[s[end]] == 0)
            {
                count--;
            }
            end++;
            
            while(count==0)
            {
                if(d > end - start) {
                    d = end-start;
                //cout<<d<<endl;
                    res = s.substr(start, d);
                }
                
                if(++mp[s[start]] == 1) count++;
                
                start++;
            }
        }
        
        return res;
    }
};