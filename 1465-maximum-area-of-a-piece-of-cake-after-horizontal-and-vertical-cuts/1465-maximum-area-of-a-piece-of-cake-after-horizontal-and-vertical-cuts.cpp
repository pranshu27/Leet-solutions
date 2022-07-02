class Solution {
public:
    static
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(0);
        
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        long long mh = max(hc[0], h - hc[hc.size()-1]), mv = max(vc[0], w - vc[vc.size()-1]);
        
        for(int i=0; i<hc.size()-1; i++)
        {
            if(mh<hc[i+1]-hc[i]) mh = hc[i+1]-hc[i];
        }
        
        for(int i=0; i<vc.size()-1; i++)
        {
            if(mv<vc[i+1]-vc[i]) mv = vc[i+1]-vc[i];
        }
        
        return (mh*mv)%1000000007;
    }
};