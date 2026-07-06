
Find Nth root of a number
   
Example 1

Input: N = 3, M = 27

Output: 3

Explanation: The cube root of 27 is equal to 3.

Solution

class Solution {
public:
    long long power(int base, int exp) {
        long long ans = 1;

        for (int i = 0; i < exp; i++) {
            ans *= base;
        }

        return ans;
    }

    int NthRoot(int N, int M) {
        int low = 1;
        int high = M;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long val = power(mid, N);

            if (val == M) {
                return mid;
            }
            else if (val < M) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};
