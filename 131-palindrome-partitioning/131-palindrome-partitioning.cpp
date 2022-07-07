class Solution {
public:
    bool isPalin(string s)
    {
        int n = s.size();
        int i=0, j =  n-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
         }
        return true;
    }
    void solve(int index, string s, vector<vector<string>> &ans, vector<string> tmp){
        if(index == s.size()){
            //cout<<"here\n";
            ans.push_back(tmp);
            return;
        }
        
        for(int i=index; i<s.size(); i++){
            string curr = s.substr(index, i-index+1);
            //cout<<curr<<endl;
            if(isPalin(curr)) {
                //cout<<"bt\n";
                tmp.push_back(curr);
                solve(i+1, s, ans, tmp);
                tmp.pop_back();//backtrack
            } 
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        
        solve(0, s, ans, tmp);
        
        return ans;
    }
};