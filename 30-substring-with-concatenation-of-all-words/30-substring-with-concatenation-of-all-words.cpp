class Solution {
public:
    bool check(unordered_map<string, int> mp, string s, int wordLen)
    {
        for(int i=0; i<s.size(); i+=wordLen)
        {
            string tmp = s.substr(i, wordLen);
            if(mp.find(tmp)!=mp.end()) {
                if(--mp[tmp]==-1) return false;
            }
            else return false;
        }
        
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> out;
        unordered_map<string, int> mp;
        
        int n = s.size();
        
        for(string w: words) mp[w]++;
        
        int wordLen = words[0].size();
        int countWords = words.size();
        
        int ws = wordLen*countWords; //window size
        
        for(int i=0; i+ws<=n; i++)
        {
            string curr = s.substr(i, ws);
            if(check(mp,curr,wordLen))
                out.push_back(i);
            
        }
        
        return out;
        
        
    }
};