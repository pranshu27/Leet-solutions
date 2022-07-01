class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& b, int truckSize) {
        
        sort(b.begin(), b.end(), cmp);
        
        int s = 0, units = 0;
        
        
        for(vector<int> v: b)
        {
            if(s+v[0]>truckSize)
            {
                units += (truckSize-s)*v[1];
                break;
            }
            s+=v[0];
            units+=v[0]*v[1];
        }
        
        return units;
    }
};