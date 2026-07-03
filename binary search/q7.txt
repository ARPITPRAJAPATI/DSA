540. Single Element in a Sorted Array
Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2


Solution


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Make mid even
            if (mid % 2 == 1) {
                mid--;
            }

            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            }
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};