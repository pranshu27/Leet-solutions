
class Solution {
public:
    bool isPossible(vector<vector<int>> &t, int energy)
    {
        for(int i=0; i<t.size(); i++)
        {
            if(t[i][1]<=energy) energy-=t[i][0];
            else return false;
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& t) {
        sort(t.begin(), t.end(), [](vector<int> &t1, vector<int> &t2) 
         { return t1[1] - t1[0] > t2[1] - t2[0]; });
        int r = 0, l= 0;
        for(vector<int> it:t) {
            r += it[1];
            l = max(l, it[0]);
        }
        //cout<<l<<" "<<r<<endl;
        int mid;
        while(l<r) {
            mid = (l+r)>>1;
            //cout<<mid<<endl;
            if(isPossible(t, mid)) {
                //cout<<"true "<<mid<<endl;
                r = mid;
            }
            else l = mid+1;
            
        }      
        
        return l;
        
    }
};