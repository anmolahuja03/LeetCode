class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // T C : O(row*col) = O(n^2)
        // S C : O(row + col)
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> rows(row, 1);
        vector<int> cols(col, 1);
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(rows[i] == 0 || cols[j] == 0) 
                    matrix[i][j] = 0;
            }
        }
    }
};