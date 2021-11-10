/* Approach 1 - Recursion
class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base Case
        if(i == m - 1 && j == n - 1)
            return grid[i][j];
            
        // Boundary Checks
        if(i >= m || j >= n)
            return INT_MAX;
        
        int option1 = helper(grid, i , j + 1);
        int option2 = helper(grid, i + 1, j);
        
        return min(option1, option2) + grid[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        return helper(grid, 0, 0);
    }
};
*/

//-------------------------------------------------------------------------------


// Approach 2 - DP Bottom Up
class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = grid[0][0];
        
        // First Row
        for(int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        
        // First Column
        for(int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};