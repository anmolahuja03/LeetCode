class Solution {
public:
    void helper(vector<vector<int>>& image, int i, int j, int source, int newColor) {
        // Boundary Conditions & Base Case
        if(i < 0 || j < 0 || i == image.size() || j == image[0].size() || image[i][j] != source || image[i][j] == newColor)
            return;
        
        image[i][j] = newColor;
        helper(image, i + 1, j, source, newColor); // Left
        helper(image, i - 1, j, source, newColor); // Right
        helper(image, i, j + 1, source, newColor); // Down
        helper(image, i, j - 1, source, newColor); // Up
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int source = image[sr][sc];
        helper(image, sr, sc, source, newColor);
        return image;
    }
};