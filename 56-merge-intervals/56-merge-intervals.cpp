class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return (a[0]<b[0]);
        });
        //int size = intervals.size();
        
        vector<vector<int>> tmp;
 
        for(const vector<int> &interval: intervals)
        {
            if(tmp.empty() || tmp.back()[1]<interval[0])                                            tmp.push_back(interval);
            else
            {
                tmp.back()[1] = max(tmp.back()[1], interval[1]);
            }
 
        }
        
        return tmp;
    }
};