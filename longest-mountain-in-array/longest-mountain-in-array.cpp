class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;
        
        for(int i = 1; i < arr.size() - 1; i++) {
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int cnt = 1;
                int j = i;
                while(j > 0 && arr[j] > arr[j - 1]) {
                    j--;
                    cnt++;
                }
                int k = i;
                while(k < arr.size() - 1 && arr[k] > arr[k + 1]) {
                    k++;
                    cnt++;
                }
                res = max(cnt, res);
            }
        }
        return res;
    }
};