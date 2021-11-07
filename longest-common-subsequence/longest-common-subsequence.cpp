class Solution {
public:
    
    int helper(string& text1, string& text2, int x, int y) {
        int dp[x + 1][y + 1];
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0; i < x + 1; i++) {
            for(int j = 0; j < y + 1; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        
        
        for(int i = 1; i < x + 1; i++) {
            for(int j = 1; j < y + 1; j++) {
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[x][y];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        int res = helper(text1, text2, n1, n2);
        return res;
    }
};