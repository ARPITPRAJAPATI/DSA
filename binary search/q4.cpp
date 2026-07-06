33. Search in Rotated Sorted Array

Solution

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int peak;

        // Find pivot (smallest element index)
        while (low < high) {
            peak = low + (high - low) / 2;

            if (nums[peak] > nums[high]) {
                low = peak + 1;
            }
            else {
                high = peak;
            }
        }

        peak = low; // pivot index

        // Search in left half [0 ... peak-1]
        low = 0;
        high = peak - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Search in right half [peak ... n-1]
        low = peak;
        high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return -1;
    }
};


// class Solution {
// public:
//     int binarySearch(vector<int>& nums, int low, int high, int target) {
//         while (low <= high) {
//             int mid = low + (high - low) / 2;

//             if (nums[mid] == target) return mid;
//             else if (nums[mid] < target) low = mid + 1;
//             else high = mid - 1;
//         }

//         return -1;
//     }

//     int search(vector<int>& nums, int target) {
//         int n = nums.size();

//         int low = 0;
//         int high = n - 1;

//         // find pivot = index of smallest element
//         while (low < high) {
//             int mid = low + (high - low) / 2;

//             if (nums[mid] > nums[high]) {
//                 low = mid + 1;
//             }
//             else {
//                 high = mid;
//             }
//         }

//         int pivot = low;

//         // search in left sorted part
//         int ans = binarySearch(nums, 0, pivot - 1, target);
//         if (ans != -1) return ans;

//         // search in right sorted part
//         return binarySearch(nums, pivot, n - 1, target);
//     }
// };