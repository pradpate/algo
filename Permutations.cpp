/*
46. Permutations
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/


class Solution {
    void permute(vector<int>& nums, int index, vector<vector<int>> &result) {
        if (index == nums.size()) {
            result.push_back(nums);
        }
        for (int i = index; i < nums.size(); i++) {
           swap(nums[i], nums[index]);
            permute(nums, index + 1, result);
           swap(nums[i], nums[index]);
        }
        
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permute(nums, 0, result);
        return result;
    }
};

