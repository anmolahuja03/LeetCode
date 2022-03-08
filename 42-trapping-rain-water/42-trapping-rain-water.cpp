class Solution {
public:
    int trap(vector<int>& height) {
        // Approach 1
        /*
        if(height.empty())
            return 0;
        int n = height.size();
        vector<int> pmax(n),smax(n);
        int amt = 0;
        //code for prefixmax
        pmax[0] = height[0];
        for(int i = 1; i < n; i++) {
            pmax[i] = max(height[i], pmax[i - 1]);
        }
        //code for suffixmax
        smax[n - 1] = height[n - 1];
        for(int i = n-2; i >= 0; i--) {
            smax[i] = max(height[i], smax[i + 1]);
        }   
        
        for(int i = 1; i < n - 1; i++) {
            amt += min(pmax[i], smax[i]) - height[i];
        }      
        return amt; 
        */
    
        
        // Approach 2
        int l = 0, r = height.size() - 1, res = 0;
        int maxLeft = 0, maxRight = 0;
        while(l <= r) {
            if(height[l] <= height[r]) {
                if(height[l] >= maxLeft) {
                    maxLeft = height[l];
                }
                else {
                    res += maxLeft - height[l];
                }
                l++;
            }
            else {
                if(height[r] >= maxRight) {
                    maxRight = height[r];
                }
                else {
                    res += maxRight - height[r];
                }
                r--;
            }
        }
        return res;
    }
};