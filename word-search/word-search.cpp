class Solution {
public:
    bool helper(int index, vector<vector<char>>& board, string word, int i, int j) {
        // Base Case
        if(index == word.size())
            return true;
        // Boundary Conditions
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index])
            return false;
        
        bool up, down, left, right;
        
        // Marking a cell as visited
        board[i][j] = '*';
       
        up = helper(index + 1, board, word, i, j - 1);
        down = helper(index + 1, board, word, i, j + 1);
        left = helper(index + 1, board, word, i + 1, j);
        right = helper(index + 1, board, word, i - 1, j);
        
        // Unmarking the cell back to original value
        board[i][j] = word[index];
        
        if(up || down || right || left)
            return true;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0] && (helper(0, board, word, i, j)))
                    return true;
            }
        }
        return false;
    }
};