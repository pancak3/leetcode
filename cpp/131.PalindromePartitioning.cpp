#include <string>
#include <vector>

using namespace std;

class Solution {

    bool isPalindrome(const string& s, int start, int end){

        if (start == end ) return true;
        int i = start, j = end;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i; --j;
        }
        return true;
    }

    void helper(string& s, vector<vector<string>>& ret, vector<string> tmp, int start) {
        int sLen = s.size();
        if (start + 1 > sLen){
            ret.push_back(tmp);
            return;
        }

        for (int i = start; i < sLen; ++i) {
            if (isPalindrome(s, start, i)) {
                tmp.push_back(s.substr(start, i - start + 1));
                helper(s, ret, tmp, i + 1);
                tmp.pop_back();
            }
        }
    }


public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        helper(s, ret, {}, 0);
        return ret;
    }
};