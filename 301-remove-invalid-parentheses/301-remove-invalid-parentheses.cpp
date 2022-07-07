class Solution {
public:
    void help(int pair, int index, int remove_left, int remove_right, const string& s, string solution, unordered_set<string>& result){
        if(index==s.size()){
            if(pair==0 && remove_left==0 && remove_right==0)    result.insert(solution);
            return;
        }
        if(s[index]=='('){
            if(remove_left > 0)     help(pair, index+1, remove_left-1, remove_right, s, solution, result);
            help(pair+1, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
        else if(s[index]==')'){
            if(remove_right > 0)     help(pair, index+1, remove_left, remove_right-1, s, solution, result);
            if(pair > 0) help(pair-1, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
        else{
            help(pair, index+1, remove_left, remove_right, s, solution+s[index], result);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        
        int l=0, r=0;
        
        for(char ch:s)
        {
            if(ch=='(') l++;
            else if(ch == ')'){
                if(l>0) l--;
                else r++;
            }
        }
        
        unordered_set<string> st;
        
        help(0, 0, l, r, s, "", st);
        
        return vector<string>(st.begin(), st.end());
    }
};