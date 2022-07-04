class Solution {
public:
    bool bs(vector<int>& arr, int ele, int n, int i)
    {
        int f = 0, l = i;
        while(f<l)
        {
            int mid = (f+l)>>1;
            
            if(arr[mid]==ele) return true;
            else if(arr[mid]<ele) f = mid + 1;
            else l = mid;
        }
        return false;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, int> mp;
        int n = arr.size();
        long long int tt = 0, curr = 0, mod = 1e9+7;
        
        for(int i=0; i<n; i++)
        {
            curr = 1;
            for(int j=0; j<i; j++)
            {
                if(arr[i]%arr[j])
                {
                    continue;
                }
                
                long long ele = arr[i]/arr[j];
                if(bs(arr, ele, n, i)) {
                    curr+=(mp[arr[j]]%mod*mp[ele]%mod)%mod;
                    curr%=mod;
                }
            }
            mp[arr[i]] = curr;
            tt += mp[arr[i]];
            tt %= mod;
        }
        
        return tt;
        
    }
};