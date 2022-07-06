class Solution {
public:
    bool solve(string num, vector<int> &ans, int index)
    {
        if(index==num.size() && ans.size()>=3) return true;
        
        int maxx = num[index]=='0'? 1:10;
        
        for(int i=1; i<=maxx&& index+i<=num.size(); i++)
        {
            long long curr = stoll(num.substr(index, i));
            
            if(curr>INT_MAX) return false;

            if(ans.size()<=1 ||  (long long)ans[ans.size()-1]+(long long)ans[ans.size()-2] == curr){
                ans.push_back(curr);
                if(solve(num, ans, index+i)) return true;
                ans.pop_back();
            }
        }
        return false;
    }
    
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;    
        solve(num, ans, 0);
        return ans;
    }
};