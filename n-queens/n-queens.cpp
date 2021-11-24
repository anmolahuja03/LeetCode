class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        // Checking vertically
        for(int i = row - 1, j = col; i >= 0; i--) {
            if(board[i][col] == 'Q')
                return 0;
        }
        
        // Checking for left diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q')
                return 0;
        }
        
        // Checking for right diagonal
        for(int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
            if(board[i][j] == 'Q')
                return 0;
        }
        return 1;
    }
    
    void solve(int n, int row, vector<string>& board, vector<vector<string>>& res) {
        // Base Case
        if(row == board.size()) {
            // When no queens are left
            // means we have placed all the
            // queens at correct place
            if(n == 0) {
                res.push_back(board);
            }
            return;
        }
        
        for(int col = 0; col < board.size(); col++) {
            // If the place is safe
            if(isSafe(board, row, col)) {
                // Place the queen
                board[row][col] = 'Q';
                // Recursive Call
                solve(n - 1, row + 1, board, res);
                // Backtrack
                board[row][col] = '.';
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        
        solve(n, 0, board, res);
        return res;
    }
};