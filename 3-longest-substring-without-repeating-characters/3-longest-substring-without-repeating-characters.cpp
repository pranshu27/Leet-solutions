class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i=0, j=0, count=0;
        int ans=0;
        unordered_map<char,int>mp;

        while(j<n){
            mp[s[j]]++;
            count++;
            if(mp[s[j]]>1){
                ans=max(ans,count-1);
                while(mp[s[j]]>1 && i<=j){
                    mp[s[i]]--;
                    i++;
                }
                count=j-i+1;
            }
           j++; 
        }


        return max(ans,count);
    }
};