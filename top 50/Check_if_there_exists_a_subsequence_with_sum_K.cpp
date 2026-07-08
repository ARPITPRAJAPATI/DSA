Check if there exists a subsequence with sum K

Given an array nums and an integer k. R﻿eturn true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.


Example 1

Input : nums = [1, 2, 3, 4, 5] , k = 8

Output : Yes

Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.

solution:

class Solution {
public:
    bool helper(int i, vector<int>& nums, int k) {
        if (i == nums.size()) {
            if (k == 0) {
                return true; // tell at the end of tree 
            }
            return false;
        }

        bool take = helper(i + 1, nums, k - nums[i]); // take value and decrease after that, put that into var
        bool notTake = helper(i + 1, nums, k); // not take and and put value,

        return take || notTake; // return any possible value
    }

    bool checkSubsequenceSum(vector<int>& nums, int k) {
        return helper(0, nums, k);
    }
};

tips.. 1. make a tree till end 
       2. capture true and false in every possible directons
       3. at the end if k == 0 return true as false
       4. return possible values from every end and return that
       5. return value of helper