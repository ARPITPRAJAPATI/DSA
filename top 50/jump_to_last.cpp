55. Jump Game

You are given an integer array nums

You are initially positioned at the array
first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 
Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

solution:

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;  //this will tell max reach from where you are
        for(int i=0;i<nums.size();i++){
            if (i>maxReach){ // if we do not reach to any index using max reach
                return false; // just return false
            }
            maxReach = max (maxReach,i+nums[i]);  // update the max 
        }
        return true; // else return true that we can go to last 
    }
};

