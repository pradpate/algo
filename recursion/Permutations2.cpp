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
    void recursion(vector<int> num, int index, vector<vector<int> > &res) {
        if (index== num.size()-1) {
            res.push_back(num);
            return;
        }
        for (int i = index; i < num.size(); i++) {
            if (index!= i && num[index] == num[i]) continue;
            swap(num[index], num[i]);
            recursion(num, index +1, res);
        }
    }
    public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, res);
        return res;
    }
};
