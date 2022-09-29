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
    map<int, vector<int>> adj;
    void dfs(TreeNode* root, int par){
        if(!root){
            return;
        }
        if(par  != -1){
            adj[par].push_back(root ->val);  // connecting parent node with it's child
            adj[root ->val].push_back(par); // connecting child node with it's parent
        } 
        dfs(root ->left, root->val); 
        dfs(root ->right, root->val);

    }
    

    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;

        adj.clear();
        //adj.resize((int)1e5+1, vector<int>{});
        dfs(root, -1);
        
        
        unordered_set<int> visited;        
        queue<int> q;
        q.push(start);
        visited.insert(start);
        
        int time = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--){
                auto node = q.front(); q.pop();
                
                for(auto it: adj[node])
                {
                    if(!visited.count(it)){
                        visited.insert(it);
                        q.push(it);
                    }
                }
            }
            time++;
        }
        
        return time-1;
        
    }
};