class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Approach 1 -> Maintaining counts of 0, 1 and 2 and updating the array
        
        
        // Approach 2 -> DNF Sort
        // T C : O(n)
        // S C : O(1)
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
                mid++;
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};