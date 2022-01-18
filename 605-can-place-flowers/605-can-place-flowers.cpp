class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // Check for first and last 0's
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        
        // For elements in between
        for(int i = 1; i < flowerbed.size() - 1; i++) {
            if(flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    n--;
                    i++;
                }
            }
        return (n <= 0);
    }
};