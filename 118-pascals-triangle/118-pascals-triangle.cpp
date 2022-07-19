class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out;
        out.push_back(vector<int>{1});
        if(numRows==1) return out;
        if(numRows>1) out.push_back(vector<int>{1,1});
        vector<int> tmp;
        for(int i=0; i<numRows-2; i++)
        {
            vector<int> &prev = out.back();
            //for(auto it: prev) cout<<it<<" "; cout<<endl;
            
            tmp.push_back(1);
            for(int j = 0; j<prev.size()-1; j++)
            {
                tmp.push_back(prev[j]+prev[j+1]);
            }
            tmp.push_back(1);
           // for(auto it: tmp) cout<<it<<" "; cout<<endl;
            out.push_back(tmp);
            tmp.clear();
           
        }
        
        return out;
    }
};