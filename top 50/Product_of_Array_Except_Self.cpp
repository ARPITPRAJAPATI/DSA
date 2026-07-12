238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is
equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

solution:

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>v(nums.size()); 
        v[0]=1;  // fix the 0 index because left of 0 is nothing
        for(int i = 1; i<nums.size();i++){
            v[i]=v[i-1]*nums[i-1];    // at current value we get the left product in result
        }
        int right = 1; //for right product 
        for(int i = nums.size()-1;i>=0;i--){
            v[i] = v[i] * right; // update the value of a current index by mul the left part and the new right part
            right *= nums[i]; // update right for interation 
        }
        return v; // return result 
    }
};   

tips .. solve using prefix from left to right