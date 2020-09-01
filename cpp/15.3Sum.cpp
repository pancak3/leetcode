#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int nNums = nums.size();
        vector<vector<int>> ret;
        if (nNums < 3) return ret;

        sort(nums.begin(), nums.end());

        int aPos, bPos, c;

        for (int i = 0; i < nNums; ++i ) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[ i - 1 ] == nums[i])
                continue;

            aPos = i + 1;
            bPos = nNums - 1;
            c = 0 - nums[i];


            while (aPos < bPos) {

                if (nums[aPos] + nums[bPos] == c) {
                    ret.push_back({nums[i], nums[aPos], nums[bPos]});
                    do
                        ++aPos;
                    while (aPos + 1 < bPos && nums[aPos - 1] == nums[aPos]);
                    do
                        --bPos;
                    while (bPos - 1 > aPos && nums[bPos + 1] == nums[bPos]);
                }
                else if (nums[aPos] + nums[bPos] < c)
                    ++aPos;
                else
                    --bPos;
            }
        }

        return ret;
    }
};