class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i + 1] <= nums[i]) {
                int temp = nums[i] - nums[i + 1] + 1;
                ans += temp;
                nums[i + 1] += temp;
            }
            else 
                continue;
        }
        return ans;
    }
};