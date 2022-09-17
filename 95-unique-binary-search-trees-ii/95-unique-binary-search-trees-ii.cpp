/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<TreeNode *> solve(int l, int r)
    {
        if(l>r) return {NULL};
        if(l==r) return {new TreeNode(l)};
        vector<TreeNode*> ans;
        for(int tmp = l;  tmp <=r; tmp++){
            vector<TreeNode *> left = solve(l, tmp-1);
            vector<TreeNode *> right = solve(tmp+1, r);
            
            for(auto l: left)
                for(auto r: right)
                    ans.push_back({new TreeNode(tmp, l, r)});
            
        }
        
        return ans;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};