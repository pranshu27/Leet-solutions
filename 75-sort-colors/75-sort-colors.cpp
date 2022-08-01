class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size();
        int l=0, mid=0, r=n-1;
        
        while(mid<=r)
        {
            if(a[mid]==0){
                swap(a[mid],a[l]);
                l++;
                mid++;
            }
            else if (a[mid]==2)
            {
                swap(a[mid], a[r--]);
            }
            
            else{
                mid++;
            }
            
            //cout<<l<<"\t"<<mid<<"\t"<<r<<endl;
            

        }
        
    }
};