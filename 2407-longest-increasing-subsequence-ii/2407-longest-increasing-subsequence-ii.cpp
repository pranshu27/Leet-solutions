class Solution {
public:
    
    int query(int ss, int se, int qs, int qe, int index, vector<int>& tree){
        if(qs<=ss && se<=qe) return tree[index];
        if(qe < ss || qs > se) return 0;
        
        int mid = (ss+se)>>1;
        int left =  query(ss, mid, qs, qe, 2*index+1, tree);
        int right =  query(mid+1, se, qs, qe, 2*index+2, tree);
        
        return max(left, right);
        
    }
    void update(int ss, int se, int i, int inc, int index,vector<int>& tree)
    {
        if(i<ss || i>se) return;
        
        if(ss == se) {
            tree[index]=inc;
            return;
        }
        
        int mid = (ss+se)>>1;
        update(ss, mid, i, inc, 2*index+1, tree);
        update(mid+1, se, i, inc, 2*index+2, tree);
        
        tree[index] = max(tree[2*index+1], tree[2*index+2]);
        
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int x = 1;
        while(x <= 200000) x *= 2;
        
        
        vector<int> tree(2*x, 0);
        int res=0;
        for(auto it: nums)
        {
            int left = max(1, it-k);
            int right = it-1;
            int curr = 1+query(0,x-1,left, right, 0, tree);
            res = max(res, curr);
            update(0, x-1, it, curr, 0, tree);
        }
        
        //for(int i=0; i<20; i++) cout<<tree[i]<<" ";
        return res;
    }
};