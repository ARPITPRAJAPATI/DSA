 Combination Sum

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]


solution:

class Solution {
public:
    void helper(int i,int target,vector<int> temp,vector<int>& candidates, vector<vector<int>>& result) {
        if (i >= candidates.size()) {
            if (target == 0) {
                result.push_back(temp);
            }
            return;
        }
        if (candidates[i] <= target) {
            temp.push_back(candidates[i]);
            helper(i, target - candidates[i], temp, candidates, result);
            temp.pop_back();
        }
        helper(i + 1, target, temp, candidates, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,int target ) {
        vector<vector<int>> result;
        vector<int> temp;
        helper(0, target, temp, candidates, result);
        return result;
    }
};

