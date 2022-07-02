class Solution {
public:
    static bool cmp(pair<int, int > a, pair<int, int > b){
        return a.first > b.first;
    }
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pair<int, int>> eng(n);
        
        for(int i=0; i<n; i++)
        {
            eng.push_back({e[i], s[i]});
        }
        
        sort(eng.begin(), eng.end(), cmp);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
         
        long long overall=0, maxx = -1;
        for(int i=0; i<n; i++){
            long long curr_min = eng[i].first;
            
            long long ts = overall + eng[i].second;
            
            if(curr_min * ts > maxx) maxx = (curr_min * ts) ;
            
            pq.push(eng[i].second);
            
            overall+=eng[i].second;
            
            if(pq.size()>k-1)
            {
                overall-=pq.top();
                pq.pop();
            }
        }
        
        return maxx%1000000007 ;
    }
};