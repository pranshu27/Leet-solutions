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
    bool solve(TreeNode* root, int tar)
    {
        if(!root->left && !root->right) {
            if(tar==root->val) return true;
            return false;
        }
        
        bool l=false, r=false;
        if(root->left) l = solve(root->left, tar-root->val);
        if(root->right) r = solve(root->right, tar-root->val);
        
        return l||r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) {
            // if(targetSum==0) return true;
            return false;
        }
        return solve(root, targetSum);
    }
};