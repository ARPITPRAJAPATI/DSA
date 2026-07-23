322. Coin Change

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0


Solution:

class Solution {
public:
    int helper(int amount, vector<int>& coins, vector<int>& dp) {
        if (amount == 0) {
            return 0;    // base case if we get the zero no need to add more coins 
        }

        if (amount < 0) {
            return 1e9;  // if we get less than 0 amount return 1e9 //that we dont get no of coins for amount zero
        }

        if (dp[amount] != -1) {
            return dp[amount];  // store the min number of coins for every amount from 0 to amount n
        }

        int ans = 1e9; // take INT_MAX AS ANS

        for (int coin : coins) { // take every coin
            int take = 1 + helper(amount - coin, coins, dp); // take a coin and in helper put the remaning amount to find min coin to get tho
            ans = min(ans, take); // compare with take for every possible coin
        }

        return dp[amount] = ans; // store the amount in dp and return the min coins for (amount of function)
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1); // create  a vector for dp;

        int ans = helper(amount, coins, dp); // helper function to get min

        if (ans >= 1e9) {
            return -1;  // if there is no min return -1
        }

        return ans; // else return min as ans 
    }
};

tips ...

Example for amount = 11:

coin 1 lo → 1 + helper(10)
coin 2 lo → 1 + helper(9)
coin 5 lo → 1 + helper(6)

Jo minimum answer dega, woh choose karenge.