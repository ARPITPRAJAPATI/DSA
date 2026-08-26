300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4

Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Solution: 

class Solution {
public:
    int dp[2501][2501];

    int solve(vector<int>& nums, int i, int prev) {
        if (i == nums.size()) return 0;

        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

        //  skip
        int notTake = solve(nums, i + 1, prev);

        //  take
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(nums, i + 1, i);
        }

        return dp[i][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};