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
    int index;
    TreeNode *solve(vector<int>& pre, int minn, int maxx, int &n)
    {
        if(index>=n) return NULL;
        TreeNode *root = NULL;
        int key = pre[index];
        if(key>minn && key<maxx) {
            root = new TreeNode(pre[index]);
            index += 1;
            root->left = solve(pre, minn, key,  n);
            root->right = solve(pre, key, maxx, n);
        }
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n = pre.size();
        index = 0;
        
        return solve(pre, INT_MIN, INT_MAX, n);
        
    }
};