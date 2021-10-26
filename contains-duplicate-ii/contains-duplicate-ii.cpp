class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        // Using Maps
        // T C : O(n)
        // S C : O(n)
//         unordered_map<int, int> M;
//         for(int i = 0; i < nums.size(); i++) {
//             if(M.find(nums[i]) != M.end()) {
//                 int difference = abs(i - M[nums[i]]);
                
//                 if(difference <= k)
//                     return true;  
//             }
//             M[nums[i]] = i;            // Updating the latest occurence
//         }
//         return false;
        
        
        
        // Sorting
        // T C : O(nlogn)
        // S C : O(n)
        vector<pair<int, int>> temp;
        
        if(k == 0) 
            return false;
        
        for(int i = 0; i < nums.size(); i++) {
            temp.push_back({nums[i], i});
        }
        
        // Will sort on the basis of first value i.e, nums[i]
        sort(temp.begin(), temp.end());
        
        for(int i = 0; i < temp.size() - 1; i++) {
            if(temp[i].first == temp[i + 1].first && abs(temp[i].second - temp[i + 1].second) <= k)
                return true;
        }
        return false;
    }
};