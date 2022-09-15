class Solution {
public:
    struct Node
    {
        Node *links[2];
    };
    
    Node *root;
    
    Node *getNode()
    {
        Node *tmp = new Node;
        tmp->links[0] = NULL;
        tmp->links[1] = NULL;
        return tmp;
    }
    
    
    void insert(int n)
    {
        Node *tmp = root;
        for(int i = 31; i>=0; i--)
        {
            int bit = (n>>i)&1;
            if(tmp->links[bit] == NULL){
                tmp->links[bit] = getNode();
            }
            tmp = tmp->links[bit];
        }
    }

    int findMax(int x)    
    {
        int out = 0;
        Node *tmp = root;
        for(int i = 31; i>=0; i--)
        {
            int bit = (x>>i)&1;
            if(tmp->links[1-bit])
            {
                out = out | 1<<i;
                tmp = tmp->links[1-bit];
            }
            else tmp = tmp->links[bit];
        }
        return out;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        root = getNode();
        
        for(auto it: nums) insert(it);
        
        int maxx = INT_MIN;
        
        for(auto it: nums) maxx = max(maxx, findMax(it));
        
        return maxx;
        
        
        
        
        
    }
};