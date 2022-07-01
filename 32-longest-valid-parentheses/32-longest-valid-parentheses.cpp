class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> s;
        s.push(-1);
        
        int maxx = 0;
        
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]=='(') s.push(i);
            else
            {
                s.pop();
                if(s.empty()) s.push(i);
                
                maxx = max(maxx, i - s.top());
            }
        }
        
        return maxx;
    }
};