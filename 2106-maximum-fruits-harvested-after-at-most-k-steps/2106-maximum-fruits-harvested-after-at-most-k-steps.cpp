class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int mx = 2*1e5 + 2, n = fruits.size();
        vector<int> prefix(mx, 0);
        startPos++; // In order to make calculations easy as we would be requiring 'left -1' for difference between the prefix sum 
        
        for(int i = 0; i<n; i++) {
            prefix[fruits[i][0] + 1] = fruits[i][1];
        }
        for(int i = 1; i<mx; i++) {
            prefix[i] += prefix[i-1];
        }
        
        int res = 0;
		// First going 'r' steps to the right
		// If we go 'r' steps to the right, we need '2*r' steps in total to come back to 'startPos' and we are left with 'k - 2*r'  steps to travel to the left 
        for(int r = 0; r <= k; r++) {
            int right = min(mx-1, startPos + r);
            int left = max(1, startPos - max(0, (k - 2*r)));
            res = max(res, prefix[right] - prefix[left-1]);
            if(right == mx-1) break;
        }
        
		//First going 'l' steps to the left
        for(int l = 0; l <= k; l++) {
            int left = max(1, startPos - l);
            int right = min(mx-1, startPos + max(0, (k - 2*l)));
            res = max(res, prefix[right] - prefix[left-1]);
            if(left == 1) break;
        }
        
        return res;
    }
};