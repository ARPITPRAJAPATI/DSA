Count Occurrences in a Sorted Array

You are given a sorted array of integers arr and an integer target. Your task is to determine how many times target appears in arr.



Return the count of occurrences of target in the array.


Example 1

Input: arr = [0, 0, 1, 1, 1, 2, 3], target = 1

Output: 3

Explanation: The number 1 appears 3 times in the array.

class Solution {
public:
    int countOccurrences(vector<int>& arr, int target) {

        int first = -1, last = -1;
        int low = 0, high = arr.size() - 1;

        // First occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        if (first == -1) return 0;

        low = 0;
        high = arr.size() - 1;

        // Last occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return last - first + 1;
    }
};