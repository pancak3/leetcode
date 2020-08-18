#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sLen = str.size();
        int ret = 0, i = 0;
        while (i < sLen && str[i] == ' ')
            ++i;
        int isNegative = false;
        if (str[i] == '-') {
            ++i;
            isNegative = true;
        } else if (str[i] == '+') {
            ++i;
            isNegative = false;
        }

        while (i < sLen && str[i] >= '0' && str[i] <= '9') {
            if (INT_MAX / 10 < ret)
                return isNegative ? INT_MIN : INT_MAX;

            if (INT_MAX / 10 ==ret) {
                int t = str[i] - '0';
                if (isNegative && (str[i] - '0') > 7) return INT_MIN;
                else if (str[i] - '0' > 7) return INT_MAX;
            }


            // NOTE:  ret * 10 + str[i++] - '0'; causes overflow
            ret = ret * 10 + (str[i++] - '0');
        }

        return isNegative ? -ret : ret;

    }
};