class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> out;
        
        sort(products.begin(), products.end());
        
        int l = 0, r = products.size()-1;
        
        vector<string> tmp;
        for(int i=0; i<searchWord.length(); i++)
        {
            tmp.clear();
            while(l<=r && products[r][i]!=searchWord[i]) r--;
            while(l<=r && products[l][i]!=searchWord[i]) l++;
            
            for(int k = l; k<=min(l+2,r); k++)
            {
                tmp.push_back(products[k]);
            }
            out.push_back(tmp);
        }
        
        return out;
    }
};