class Solution {
public:
    string thousandSeparator(int n) {
        if(n == 0)
            return "0";
        
        string res = "";
        int cnt = 0;
        
        while(n) {
            cnt++;
            string temp = to_string(n%10);
            n = n / 10;
            res += temp;
            if(n > 0 && cnt == 3) {
                res += '.';
                cnt = 0;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};