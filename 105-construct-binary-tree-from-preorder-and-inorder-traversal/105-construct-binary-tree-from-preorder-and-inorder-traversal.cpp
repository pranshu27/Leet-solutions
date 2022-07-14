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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &index)     {
        if(start>end) return NULL;
        
        TreeNode *root = new TreeNode(preorder[index++]);
        
        int pivot = mp[preorder[index-1]];
        
        root->left = solve(preorder, inorder, start, pivot-1, index);
        root->right = solve(preorder, inorder, pivot+1, end, index);
        
        
        return root;
        
    }
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
        int index = 0;
        return solve(preorder, inorder, 0, inorder.size()-1, index);
    }
};