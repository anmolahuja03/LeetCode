/* Recursion - Brute

class Solution {
public:
    int countPaths(int m, int n, int i, int j) {
        // Base Case 
        if(i == m - 1 || j == n - 1)
            return 1;
        // Boundary Conditions
        if(i == m || j == n)
            return 0;
    
        int right = countPaths(m, n, i + 1, j);
        int down = countPaths(m, n, i, j + 1);
        
        return right + down;
    }
    
    int uniquePaths(int m, int n) {
        int ans = countPaths(m, n, 0, 0);
        return ans;
    }
};
*/

// ---------------------------------------------------------------------
// DP
class Solution {
public:
    int dp[101][101];
    int countPaths(int m, int n, int i, int j) {
        // Base Case 
        if(i == m - 1 || j == n - 1)
            return 1;
        // Boundary Conditions
        if(i == m || j == n)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = countPaths(m, n, i + 1, j);
        int down = countPaths(m, n, i, j + 1);
        
        return dp[i][j] = right + down;
    }
    
    int uniquePaths(int m, int n) {
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                dp[i][j] = -1;
            }
        }
        
        int ans = countPaths(m, n, 0, 0);
        return ans;
    }
};