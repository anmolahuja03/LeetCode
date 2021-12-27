class Solution {
public:
    bool check(int i, int j, int r, int c) {
        if(i < 0 || j < 0 || i >= r || j >= c)
            return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int fresh_cnt = 0, minutes = 0;
        queue<pair<int, int>> q;
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 1)
                    fresh_cnt++;
                else if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int m = q.front().first;
                int n = q.front().second;
                if(check(m - 1, n, r, c) && grid[m - 1][n] == 1) {
                    grid[m - 1][n] = 2;
                    fresh_cnt--;
                    q.push({m - 1, n});
                }
                if(check(m, n - 1, r, c) && grid[m][n - 1] == 1) {
                    grid[m][n - 1] = 2;
                    fresh_cnt--;
                    q.push({m, n - 1});
                }
                if(check(m + 1, n, r, c) && grid[m + 1][n] == 1) {
                    grid[m + 1][n] = 2;
                    fresh_cnt--;
                    q.push({m + 1, n});
                }
                if(check(m, n + 1, r, c) && grid[m][n + 1] == 1) {
                    grid[m][n + 1] = 2;
                    fresh_cnt--;
                    q.push({m, n + 1});
                }
                q.pop();
            }
            if(!q.empty())
                minutes++;
        }
        if(fresh_cnt == 0)
            return minutes;
        return -1;
    }
};