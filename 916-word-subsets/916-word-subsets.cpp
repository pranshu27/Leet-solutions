class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> f(26,0);
        //overall array for frequency of b
        for( const string &w: words2)
        {
            vector<int> tmp(26, 0); //temporary array
            for(const char &c:w){
                tmp[c-'a']++;
                f[c-'a'] = max(tmp[c-'a'], f[c-'a']);
            }
            
        }
        
        vector<string> out;
        
        for(const string &w:words1){
            vector<int> tmp(26);
            for(const char &c: w)
            {
                tmp[c-'a']++;
            }
            
            int i;
            for(i=0; i<26; i++)
            {
                if(tmp[i]<f[i]) break;
            }
            //for(auto it: tmp) cout<<it<<" "; cout<<endl;
        
            if(i==26) out.push_back(w);
        }
        return out;
    }
};