//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

    public:
    
    int combine(int n, string s[]){
        //code
        int rr = 0, bb = 0, br = 0, rb = 0;
        string ele;
        for(int i = 0; i < n; i++)
        {
            ele = s[i];
            if(ele.front() == 'R' and ele.back() == 'R') rr++;
            if(ele.front() == 'B' and ele.back() == 'B') bb++;
            if(ele.front() == 'R' and ele.back() == 'B') rb++;
            if(ele.front() == 'B' and ele.back() == 'R') br++;
        }//In this for loop we are finding the various buckets of words.
        int ans = 0;
        ans += max(rr, bb);//All rr can be combined to form a big string similar is the case with bb.
        if(rb || br)//if atleast one of these is present:
        {
            ans += 2 * min(rb, br);// a. We will join the strings consecutively and form one big string.
            if(rb != br) ans++;// b. If these numbers are not equal we can begin the big string formed in a using the one which has a larger value, thus a +1 in ans.
            ans += min(rr, bb);//c. Finally the two big strings formed from rr and bb can be joined using the string formed in b.
        }
        if(ans == 1) ans--;// if we couldn't find even one match then as per the question we must return 0.
        // cout << ans * ele.length()<< "\n";// multiplying with the length of each word.
        
        return ans * ele.length();
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        string s[n];
        for(i=0;i<n;i++)
            cin>>s[i];
        Solution ob;
        cout<<ob.combine(n,s)<<endl;
    }
    return 0;
}

// } Driver Code Ends