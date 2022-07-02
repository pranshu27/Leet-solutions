class Solution {
public:
    static
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        hc.insert(hc.begin(), 0);
        vc.insert(vc.begin(), 0);
        
        hc.push_back(h);
        vc.push_back(w);
        
        long long mh = hc[1]-hc[0], mv = vc[1]-vc[0];
        
        for(int i=1; i<hc.size()-1; i++)
        {
            if(mh<hc[i+1]-hc[i]) mh = hc[i+1]-hc[i];
        }
        
        for(int i=1; i<vc.size()-1; i++)
        {
            if(mv<vc[i+1]-vc[i]) mv = vc[i+1]-vc[i];
        }
        
        return (mh*mv)%1000000007;
        
        
        
    }
};