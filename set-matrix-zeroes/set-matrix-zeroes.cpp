class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /* // Brute
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> rows(r, 1);
        vector<int> cols(c, 1);
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = 0;
                    cols[j] = 0;
                }
             }
        }
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(rows[i] == 0 || cols[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        */
        
        //Optimal
        int r = matrix.size();
        int c = matrix[0].size();
        bool flagR = 0, flagC = 0;
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    if(i == 0) flagR = 1;
                    if(j == 0) flagC = 1;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = 1; i < r; i++) {
            for(int j = 1; j < c; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        if(flagR) {
            for(int i = 0; i < c; i++) {
                matrix[0][i] = 0;
            }
        }
        if(flagC) {
            for(int i = 0; i < r; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
