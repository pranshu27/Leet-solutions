class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        
        queue<int> q;
        q.push(1);
        
        map<int, int> m;
        m[1] = 0;
        
        while(!q.empty())
        {
            int pos = q.front();
            q.pop();
            //cout<<pos<<endl;
            
            for(int i=1; pos+i<=n*n&&i<=6; i++)
            {
                
                int newPos = pos+i;
                int row = n-1-((newPos-1)/n);
                int col = (newPos-1)%n;
                if((n%2==1 && row%2==1)||(n%2==0 && row%2==0))
                {
                    col = n-1-col;
                }
                
                int next = board[row][col];
                if(next>0) newPos = next;
                
                if(newPos==n*n) return m[pos]+1;
                
                if(m.find(newPos)==m.end()) {
                    
                    m[newPos] = m[pos]+1;
                    //cout<<newPos<<" "<<m[newPos]<<endl;
                    q.push(newPos);
                }
 
            }
            
            
        }
        return -1;
    }
    
};