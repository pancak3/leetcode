class Solution {
public:
    int reverse(int x) {
        int ret = 0, digit;
        while (x != 0) {
            digit = x % 10;
            x /= 10;
            if (ret < INT_MIN / 10 || (INT_MIN / 10 == ret && digit < -8)) return 0;
            if (ret > INT_MAX / 10 || (INT_MAX / 10 == ret && digit > 7)) return 0;

            ret = ret*10 + digit;
        }

        return ret;
    }
};