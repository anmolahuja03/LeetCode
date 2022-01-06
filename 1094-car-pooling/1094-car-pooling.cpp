class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> pool(1001, 0);
        int sum = 0, num, from, to;
        for(int i = 0; i < trips.size(); i++) {
            num = trips[i][0];
            from = trips[i][1];
            to = trips[i][2];
            pool[from] += num;
            pool[to] -= num;
        }
        for(int i = 0; i < pool.size(); i++) {
            sum += pool[i];
            if(sum > capacity)
                return false;
        }
        return true;
    }
};