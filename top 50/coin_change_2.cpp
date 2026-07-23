518. Coin Change II

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.


 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1

Solution:

class Solution {
public:
    int helper(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) {
            return 1;
        }

        if (i == coins.size()) {
            return 0;
        }

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        int take = 0;

        if (coins[i] <= amount) {
            take = helper(i, amount - coins[i], coins, dp);
        }

        int notTake = helper(i + 1, amount, coins, dp);

        return dp[i][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return helper(0, amount, coins, dp);
    }
};


tips: 
     1. this q will ask give me all ways to get the no of coins for amount;
     2. take and not take at every possible point we get some combination return 1 
     3. else return 0,