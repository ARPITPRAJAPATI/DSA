Floor and Ceil in Sorted Array

Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.


Example 1

Input : nums =[3, 4, 4, 7, 8, 10], x= 5

Output: 4 7

Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.  

Solution:

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
       int low = 0;
       int high = nums.size()-1;
       vector<int>v={-1,-1};

       if(x<nums[0]){
           v[0]=-1;
           v[1]=nums[0];
           return v;
       }
       if(x>nums[high]){
           v[0]=nums[high];
           v[1]=-1;
           return v;
       }
       while(low<=high){
        int mid = low + (high - low) / 2;
         if(nums[mid]==x){
            return {nums[mid],nums[mid]};
         }
         else if (nums[mid]<x){
            v[0]=nums[mid];
            low = mid+1;
         }
         else {
            v[1]=nums[mid];
            high = mid-1;
         }
       }
       return v;
    }
}; 
