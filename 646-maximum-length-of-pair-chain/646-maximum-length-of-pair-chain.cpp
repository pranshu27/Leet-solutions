class Solution {
public:
    
    static bool comp(vector<int> a, vector<int> b)
    {
        return a[1]<b[1];
    }
    
    int solve(int i, int j, vector<vector<int>>& pairs, int n)
    {
        if(j>=n) return 0;
        
        if(pairs[i][1] < pairs[j][0])
        {
            return 1+solve(j, j+1, pairs, n);
        }
        else return solve(i, j+1, pairs, n);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        //for(auto a:pairs) cout<<a[0]<<" "<<a[1]<<endl;
        int n = pairs.size();
        return 1+solve(0, 1,pairs, n);
    }
};