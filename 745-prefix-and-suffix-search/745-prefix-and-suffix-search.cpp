class WordFilter {
public:
    unordered_map<string, int> mp;
    WordFilter(vector<string>& words) {
        string pref, suff;
        int k=0;
        for(auto word: words)
        {
            for(int i = 1; i<=word.size(); i++)
            {
                pref = word.substr(0, i);
                for(int j = 0; j<word.size(); j++)
                {
                    suff = word.substr(j, word.size());
                    mp[pref+"@"+suff] = k+1;
                }
            }
            k++;
        }
        
        //for(auto m: mp) cout<<m.first<<" "<<m.second<<endl;
        
    }
    
    int f(string prefix, string suffix) {
        return mp[prefix+'@'+suffix]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */