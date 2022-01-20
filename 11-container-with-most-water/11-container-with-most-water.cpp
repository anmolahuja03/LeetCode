class Solution {
public:
    int maxArea(vector<int>& arr) {
        int low = 0, high = arr.size() - 1, res = 0, currentArea;
        while(low < high) {
            currentArea = min(arr[low], arr[high]) * (high - low);
            res = max(currentArea, res);
            if(arr[low] < arr[high])
                low++;
            else 
                high--;
        }
        return res;
    }
};