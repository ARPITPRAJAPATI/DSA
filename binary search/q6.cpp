Find out how many times the array is rotated

Example 1

Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]



//Solution


class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int low = 0;
        int high = nums.size()-1;
        while(low<high){
            int mid = low + (high-low)/2;
            if(nums[high]<nums[mid]){
                low = mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};