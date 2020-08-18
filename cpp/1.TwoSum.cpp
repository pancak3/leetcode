#include <vector>
#include "unordered_map"

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff_indices;
        vector<int> ans;
        int diff;
        for(int i = 0; i < nums.size(); i++){
            diff = target - nums[i];
            if(diff_indices.find(diff) != diff_indices.end()){
                ans.push_back(i);
                ans.push_back(diff_indices[diff]);
                break;
            }else{
                diff_indices.insert(pair<int, int>(nums[i], i));
            }
        }
        return ans;
    }
};

