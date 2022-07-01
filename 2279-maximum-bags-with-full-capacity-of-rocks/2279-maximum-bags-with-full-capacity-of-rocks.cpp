class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int ad) {
        vector<int> m;
        
        for(int i=0; i<cap.size(); i++)
        {
            m.push_back(cap[i]-rocks[i]);
        }
        
        sort(m.begin(), m.end());
        
        int c = 0, i=0;
        while(i<m.size()&&ad>0)
        {
            if(ad - m[i]==0){
                c++;
                break;
            }
            else if(ad - m[i]>0) c++;
            
            ad-=m[i++];
        }
        
        return c;
        
        
        
        
    }
};