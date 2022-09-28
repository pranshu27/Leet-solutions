class Solution {
public:
    struct Node
    {
        Node *children[26];
        int count;
    };
    
    Node *getNode()
    {
        Node *temp = new Node;
        for(int i=0; i<26; i++)
        {
            temp->children[i] = NULL;
        }
        temp->count = 0;
        return temp;
    }
    
    void insert(Node *root, string s)
    {
        Node *t = root;
        for(const char &c: s)
        {
            int index = c-'a';
            if(t->children[index] == NULL) {
                t->children[index] = getNode();
            }
            
            (t->children[index]->count)++;
            t = t->children[index];
        }
    }
    
    int search(Node *root, string s)
    {
        int out = 0;
        Node *t = root;
        for(const char &c: s)
        {
            int index = c-'a';
            if(t->children[index] != NULL) {
                out += t->children[index]->count;
            }
            
            t = t->children[index];
            
        }
        return out;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>  ans;
        Node *root = getNode();
        for(const string &w: words) insert(root, w);
        for(const string &w: words) ans.push_back(search(root, w));
        return ans;
    }
};