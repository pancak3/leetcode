//
// Created by Qifan Deng on 18/8/20.
//

#include "iostream"
#include <vector>
#include "1.TwoSum.cpp"

using namespace std;
int main() {
    vector<int> a = {1, 2, 3};
    vector<int> b = {3, 4};
    Solution solution1;
    for (auto n : solution1.twoSum(a, 5)) {
        cout << n << " ";
    }
    cout << endl;
}
