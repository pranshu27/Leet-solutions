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
    TreeNode *solve(TreeNode *root){
        if(!root) return NULL;
        
        TreeNode *tmp = root->right;
        
        root->right = solve(root->left);
        root->left = NULL;
        
        TreeNode *var = root;
        while(var->right) var = var->right;
        
        var->right = solve(tmp);
        return root;
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};