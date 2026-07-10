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
                result.push_back(temp); //base condition ofcourse
            }
            return;
        }
        if (candidates[i] <= target) {
            temp.push_back(candidates[i]); 
            helper(i, target - candidates[i], temp, candidates, result); // to take and explore every possible way.
            temp.pop_back(); // forward to not take
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

tips.. 1. make a tree for every possible value
       2. base condition when we reach the end of the tree
       3. take only if value is less then target.
       4. take and not take condition
       5. first take that element explore then remove. so => we can not take
       6. in not take just increase i