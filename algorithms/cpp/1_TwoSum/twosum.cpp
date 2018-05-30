#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
        return indices;
    }
};

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;

    Solution s;

    vector<int> indices = s.twoSum(nums, target);

    cout << "indices: [";
    for (vector<int>::const_iterator iter = indices.begin(); iter != indices.end(); iter++) {
        cout << (*iter) << ", ";
    }
    cout <<"]" << endl;
    return 0;
}
