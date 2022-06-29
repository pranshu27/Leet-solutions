class Solution {
public:
 
    int maxProfit(int k, vector<int>& prices) {
        vector<int> curr(2*k+1, 0);
        vector<int> next(2*k+1, 0);
        
        
        for(int i=prices.size()-1; i>=0; i--){
            for(int j=2*k-1; j>=0; j--){
                if(j%2==0){
                    curr[j] = max(-prices[i]+next[j+1],  next[j]);
                }
                else{
                    curr[j] = max(prices[i]+next[j+1],  next[j]);
                }
                
                next = curr;
                
            }
        }
         
        return curr[0];
    }
};

