class Solution {
public:
    // T C : O(nlogn)
    // S C : O(n)
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> M;
        vector<int> res;
        for(auto x : nums) {
            M[x]++;
        }
        
        vector<pair<int, int>> temp;
        for(auto x : M) {
            temp.push_back({x.second,x.first});
        }
        
        sort(temp.begin(), temp.end(), greater<pair<int, int>>());
        
        int i = 0;
        while(k > 0) {
            res.push_back(temp[i].second);
            i++;
            k--;
        }
        return res;
    }
};