class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sorting based on start time
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        for(int i = 0; i < intervals.size(); i++) {
            if(res.empty()) {
                res.push_back(intervals[i]);
            }
            else {
                vector<int>& temp = res.back();
                int x = temp[1];
                
                // Case 1 : Overlapping intervals found
                if(intervals[i][0] <= x) {
                    temp[1] = max(x, intervals[i][1]);
                }
                // Case 2 : Overlapping not found
                else {
                    res.push_back(intervals[i]);
                }
            }
        }
        return res;
    }
};