class Solution {
public:
    int ans;
    int n;
    vector<int> v;
    void check(int ind,int cur)
    {
        if(ind==n)
        {
            return ;
        }
        if((cur^v[ind])==(cur|v[ind]))
        {
            // cout<<"hi";
            ans = max(ans,__builtin_popcount(cur|v[ind]));
            check(ind+1,cur|v[ind]);
        }
        check(ind+1,cur);
    }
    int maxLength(vector<string>& arr) {
        
        
        v.clear();
        for(auto s: arr)
        {
            int n = s.size();
            int curr = 0;
            for(int i=0; i<n; i++)
            {
                int index = s[i] - 'a';
                if((curr>>index)&1)
                {
                    curr = 0;
                    break;
                }
                else curr = (1<<index) | curr;
            }
            
            if(curr) v.push_back(curr);
        }
        
        n = v.size();
        
        if(n==1) return __builtin_popcount(v[0]);
        ans = 0;
        check(0, 0);
        
        return ans;
    }
};