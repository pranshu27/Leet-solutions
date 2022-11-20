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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> out;
        
        stack<TreeNode*> s;
        stack<int> tmp;
        s.push(root);
        
        if(!root) return out;
        while(!s.empty()){
            
            auto t = s.top();
            s.pop();
            
            tmp.push(t->val);
            
            if(t->left) s.push(t->left);
            if(t->right) s.push(t->right);
        }
        
        while(!tmp.empty()) {
            out.push_back(tmp.top());
            tmp.pop();
        }
        
        return out;
        
    }
};