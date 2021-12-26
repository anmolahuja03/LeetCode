class Solution {
public:
    bool check(int i, int j, int r, int c) {
        if(i < 0 || j < 0 || i >= r || j >= c)
            return false;
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> output(r, vector<int>(c, -1));
        queue<pair<int, int>> q;
        // Marking 0's in mat as it is in output as
        // distance from 0 will be 0 only at the 
        // same time pushing the coordinates in queue
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    output[i][j] = 0;
                }
            }
        }
        // Performing BFS on multiple nodes
        // Checking neighbours->If Valid->Adding them to the queue
        // ->adding the correct value in output mat accordingly
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            if(check(i + 1, j, r, c) && output[i + 1][j] == -1) {
                q.push({i + 1, j});
                output[i + 1][j] = output[i][j] + 1;
            }
            if(check(i - 1, j, r, c) && output[i - 1][j] == -1) {
                q.push({i - 1, j});
                output[i - 1][j] = output[i][j] + 1;
            }
            if(check(i, j + 1, r, c) && output[i][j + 1] == -1) {
                q.push({i, j + 1});
                output[i][j + 1] = output[i][j] + 1;
            }
            if(check(i, j - 1, r, c) && output[i][j - 1] == -1) {
                q.push({i, j - 1});
                output[i][j - 1] = output[i][j] + 1;
            }
            q.pop();
        }
        return output;
    }
};