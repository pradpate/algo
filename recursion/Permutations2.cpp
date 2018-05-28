/*
47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

class Solution {
    void permute(vector<int> nums, int index, vector<vector<int>> &result) {
        if (index == nums.size()) {
            result.push_back(nums);
        }
        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[index] == nums[i])  continue; 
            swap(nums[i], nums[index]);
            permute(nums, index + 1, result);
        }

        return;
    }    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(begin(nums), end(nums));
        permute(nums, 0, result);
        return result;        
    }
};

