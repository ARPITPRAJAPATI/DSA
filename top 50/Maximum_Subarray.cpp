Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

 // kadence

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

solution:

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxy = INT_MIN;
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum = sum+nums[i];
            // if(sum>maxy){
            //     maxy = sum;
            // }
            maxy = max(sum,maxy);
            
            if(sum<0){
                sum = 0;
            }
        }
        return maxy;
    }
};   