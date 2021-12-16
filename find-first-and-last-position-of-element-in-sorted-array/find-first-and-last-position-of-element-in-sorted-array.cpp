class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        vector<int> res{-1, -1};
        
        while(low <= high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) {
                res[0] = mid;
                high = mid - 1;
            }
            else if(target > nums[mid]) {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        
        low = 0, high = nums.size() - 1;
        while(low <= high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) {
                res[1] = mid;
                low = mid + 1;
            }
            else if(target > nums[mid]) {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return res;   
    }
};