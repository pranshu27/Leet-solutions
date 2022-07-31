class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());
        
        int cnt = 0, prev = 0, prevS = 0;
        int n = grades.size();
        
        int curr_size=0,curr_sum = 0; 
        for(int i=0; i<n; i++)
        {
            curr_size++;
            curr_sum+=grades[i];
            if(curr_size > prev && curr_sum>prevS) {
                prev = curr_size;
                prevS = curr_sum;
                curr_size = 0;
                curr_sum = 0;
                cnt ++;
            }

        }
        
        return cnt;
    }
};