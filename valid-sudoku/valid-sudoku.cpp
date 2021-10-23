class Solution {
public:
    // T C : O(n^2)
    // S C : O(n)
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        unordered_map<char, set<char>> hashrow, hashcols, grid;
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] != '.') {
                    char temp = board[i][j];
                    
                    // check for rows and cols
                    if(hashrow[i].count(temp)) 
                        return false;
                    
                    if(hashcols[j].count(temp))
                        return false;
                    
                    // check for grid
                    char box = (i/3) * 3 + j/3;
                    if(grid[box].count(temp))
                        return false;
                    
                    hashrow[i].insert(temp);
                    hashcols[j].insert(temp);
                    grid[box].insert(temp);
                }
            }
        }
        return true;
    }
};