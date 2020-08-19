class Solution {
public:
    string intToRoman(int num) {
        int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9,  5, 4, 1};
        string romans[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string ret = "";

        for (int i = 0; i < 13; i++) {
            if (num >= nums[i]) {
                int n = num / nums[i];
                num %= nums[i];
                for (int j = 0; j < n; j++) {
                    ret += romans[i];
                }
            }
        }

        return ret;
    }
};