class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<vector<int>> mp(26) , tmp(26);
        for(int i = 0; i<s.size(); i++) {
            mp[s[i] - 'a'].push_back(i);
        }
        
        int res = 0;
        
        for(const auto &word: words){
            bool found = true;
            cout<<word<<endl;
            int x = -1;
            for(char c: word){
                auto it = upper_bound( mp[c-'a'].begin(), mp[c-'a'].end(), x);
                if(it==mp[c-'a'].end())
                {
                    found=false;
                    break;
                }
                
                else x = *it;
                
            }
            //cout<<endl;
            if(found) res++;
            cout<<res<<endl;
        }
        
        
        return res;
    }
};