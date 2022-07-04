class Solution {
    bool fun(int mid, vector<vector<int>>&tasks)
    {
        int energy = mid;
        for(int i=0;i<tasks.size();i++)
        {
            if(energy >= tasks[i][1])
            {
                energy -= tasks[i][0];
            }
            else
                return false;
        }
        if(energy >=0)
            return true;
        
        return false;
    }
    static bool myfun(vector<int>&a, vector<int>&b)
    {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), myfun);
        int answer = 0;
        int l= 1, r= 100000000000;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(fun(mid,tasks))
            {
                answer = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return answer;
        
    }
};