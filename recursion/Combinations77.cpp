/*
77. Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/


class Solution {
    void combine(vector<vector<int>> &r, vector<int> &tmp, int n, int k, int index) {
        if (tmp.size() == k) { r.push_back(tmp); return;}
        for (int i = index; i <= n; i++) {
            tmp.push_back(i);
            combine(r, tmp, n, k, i+1);
            tmp.pop_back(); 
        }
        
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> tmp;
        combine(result, tmp, n,  k, 1);
        return result;
    }
};
