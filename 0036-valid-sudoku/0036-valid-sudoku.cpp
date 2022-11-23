#define vb vector<bool>
#define vvc vector<vector<char>>
class Solution {
public:
    void hash_setter (vb &hash){
        for (int i = 0; i < 10; i++) hash[i] = 0;
    }    
    
    bool row_check (vvc &board){
        vb hash (10, 0);
        
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                if (hash[board[i][j]-'0']) return 0;
                
                hash[board[i][j]-'0'] = 1;
            }
            
            hash_setter (hash);
        }
        
        return 1;
    }
    
    bool col_check (vvc &board){
        vb hash (10, 0);
        
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[j][i] == '.') continue;
                if (hash[board[j][i]-'0']) return 0;
                
                hash[board[j][i]-'0'] = 1;
            }
            
            hash_setter (hash);
        }
        
        return 1;
    }
    
    bool sub_box_check (vvc &board, int i, int j){
        vb hash (10,0);
        
        for (int k = i; k < i+3; k++){
            for (int l = j; l < j+3; l++){
                if (board[k][l] == '.') continue;
                if (hash[board[k][l]-'0']) return 0;
                
                hash[board[k][l]-'0'] = 1;
            }
        }
        
        return true;
    }
    
    bool sub_box_generate (vvc &board){
        for (int i = 0; i < 9; i+=3){
            for (int j = 0; j < 9; j+=3){
                if (sub_box_check (board, i, j) == 0) return 0;
            }
        }
        
        return 1;
    }
    
    
    bool isValidSudoku(vector<vector<char>>& board) { 
        if (!row_check (board) || !col_check (board) || !sub_box_generate (board)) return 0;
        
        return 1;
    }
};