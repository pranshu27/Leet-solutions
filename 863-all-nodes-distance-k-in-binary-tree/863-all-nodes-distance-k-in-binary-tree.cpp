/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void buildGraph(TreeNode *root, unordered_map<TreeNode *, vector<TreeNode *>> &adj)
    {
        if(!root) return;
        
        if(root->left) {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            buildGraph(root->left, adj);
        }
        
        if(root->right) {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            buildGraph(root->right, adj);
        }   
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *, vector<TreeNode *>> adj;
        buildGraph(root, adj);
        
        if(k==0) return vector<int>{target->val};
        
        unordered_map<TreeNode *, int> visited;
        vector<int> out;
        queue<TreeNode *> q;
        q.push(target);
        //visited[target]
        int dist = 0;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                TreeNode *node = q.front(); 
                q.pop();
                visited[node] = 1;
                for(auto it: adj[node])
                {
                    if(!visited[it]) {
                        q.push(it);
                    }
                }
            }
            dist++;
            if(dist==k)
            {
                while(!q.empty())
                {
                    out.push_back(q.front()->val); 
                    q.pop();
                }
                break;
            }
            
        }
        
        return out;
        
        
        
        
        
        
        
        
        
        
        
        
    }
};