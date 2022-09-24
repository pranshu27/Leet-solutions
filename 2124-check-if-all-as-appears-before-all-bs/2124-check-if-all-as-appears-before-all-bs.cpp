class Solution {
public:
    bool checkString(string s) {
        int n = s.size(), flag = false;
        for(int i=0; i<n; i++)
        {
            if(flag && s[i]=='a') return false;
            if(s[i]=='b') flag = true;
        }
        return true;
    }
};