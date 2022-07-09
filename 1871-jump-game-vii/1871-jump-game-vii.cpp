class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1]!='0')
            return false;

        int i = 0;
        queue<int> q;
        q.push(0);
        
        int yahan_tak = 0;
        while(!q.empty()){
            i = q.front();
            q.pop();
            if(i == n-1)
                return true;

            for(int j = max(i + minJump, yahan_tak); j <= min(i + maxJump, n - 1); j++){
                if(s[j] == '0')   q.push(j);
            } 
            
            yahan_tak = min(i + maxJump + 1, n);
            
        }
        return false;
    }
};