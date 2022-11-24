//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> out;
        int tot = 1<<N;
        // cout<<tot<<endl;
        for(int i=0; i< tot; i++)
        {
            int sum = 0;
            int j = 0;
            
            int curr = i;
            // cout<<curr<<endl;
            while(curr){
                if(curr&1) sum+=arr[j];
                j++;
                curr>>=1;
            }
            
            out.push_back(sum);
        }
        
        sort(out.begin(), out.end());
        return out;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends