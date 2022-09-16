class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> mp(26);
        int n = s.length();
        for(int i=0; i<n; i++) {
            mp[s[i]-'a'].push_back(i);
        }
        int res = 0;
        for(string &word: words)
        {
            bool found=true;
            int x = -1;
            for(char &c: word)
            {
                vector<int> &curr = mp[c-'a'];
                auto it = upper_bound(curr.begin(), curr.end(), x);
                if(it == curr.end()){
                    found = false;
                    break;
                }
                x=*it;
            }
            if(found) res++;
        }
        
        return res;
    }
};