class Solution {
public:
    // Checks if all the values are filled
    bool isCompleted(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.')
                    return false;
            }
        }
        return true;
    }
    
    // Checks if the value is allowed or not
    bool isValid(vector<vector<char>>& board, int row, int col, int num) {
        // Check for rows and columns
        for(int i = 0; i < 9; i++) {
            if(board[i][col] - '0' == num || board[row][i] - '0' == num)
                return false;
        }
        
        // Check for 3 x 3 grid
        for(int i = 3 * (row / 3); i < 3 * (row / 3) + 3; i++) {
            for(int j = 3 * (col / 3); j < 3 * (col / 3) + 3; j++) {
                if(board[i][j] - '0' == num)
                    return false;
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        if(isCompleted(board))
            return true;
        else {
            for(int row = 0; row < board.size(); row++) {
                for(int col = 0; col < board[0].size(); col++) {
                    if(board[row][col] == '.') {
                        for(int num = 1; num <= 9; num++) {
                            if(isValid(board, row, col, num)) {
                                board[row][col] = num + '0';
                                if(solve(board))
                                    return true;
                            }
                        }
                        board[row][col] = '.';
                        return false;
                    }
                }
            }
        }  
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};