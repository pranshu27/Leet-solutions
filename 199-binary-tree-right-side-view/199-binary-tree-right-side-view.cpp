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
    void rightViewUtil(TreeNode *root, int level, vector<int> &out)
    {
        if(root==NULL) return;

        if(level == out.size()) out.push_back(root->val);

        rightViewUtil(root->right, level+1, out);
        rightViewUtil(root->left, level+1, out);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightViewUtil(root, 0, ans);
        return ans;
        
    }
};