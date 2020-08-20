#include "string"

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9,  5, 4, 1};
        string romans[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int sLen = s.size(), i = 0, j = 0, ret = 0;

        while ( i < sLen) {
            if ((j & 1) == 0) {
                if (s[i] == romans[j][0]) {
                    ret += nums[j];
                    ++i;
                } else
                    ++j;
            } else {
                if (s[i] == romans[j][0] && s[i + 1] == romans[j][1]) {
                    ret += nums[j];
                    i += 2;
                } else
                    ++j;
            }
        }
        return ret;
    }
};