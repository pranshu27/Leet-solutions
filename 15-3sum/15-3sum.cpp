class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        { 
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]&& out.size()!=0) {
                continue;
            }
            for(int j=i+1, k = n-1; j<k; ){
                if(j>i+1 &&nums[j-1] == nums[j] && out.size()!=0) {
                    j++;
                   // cout<<"here\n";
                    continue;
                }
                    //cout<<"h\n";
                if(k<n-1 && nums[k] == nums[k+1] && out.size()!=0)
                {
                    k--;
                    continue;
                }
                if(nums[i]+nums[j]+nums[k]==0) {
                    out.push_back({nums[i],nums[j],nums[k]});
                    j++; k--;
                }
                else if(nums[i]+nums[j]+nums[k] < 0) j++;
                else k--;
            }
        }
        
        return out;
        //return  vector<vector<int>>(out.begin(), out.end());
        
    }
};