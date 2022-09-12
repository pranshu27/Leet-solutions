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
    int n;
    int status(TreeNode* root){
        if(!root) return 1;
        
        int l = status(root->left);
        int r = status(root->right);
        
        if(l==0 or r==0){
            n++;
            return 2;
        }
        
        if(l==2 or r==2){
            return 1;
        }
        
        return 0; //both l and r are 1
        
    }
    int minCameraCover(TreeNode* root) {
        n = 0;
        if(status(root)==0) return n+1;
        return n;
    }
};