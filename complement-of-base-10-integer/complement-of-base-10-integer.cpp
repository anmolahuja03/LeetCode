class Solution {
public:
    int bitwiseComplement(int num) {
        if(num == 0)
            return 1;
        long ans = 0, n = 1;
        while(num) {
            if((num & 1) == 0) 
                ans += n;
             n *=2;
             num >>= 1;
        }
        return int(ans);
    }
};