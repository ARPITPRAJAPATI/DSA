746. Min Cost Climbing Stairs

You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.


Solution:

class Solution {
public:
    int helper(int n,vector<int>& cost,vector<int>&dp){
        if (n<=1){
            return 0; // base econdition we can start from 1 or 0
        }
        if(dp[n]!=-1){
            return dp[n]; // store the min cost to get to the step n dp 
        }
        return dp[n] = min(cost[n-1]+helper(n-1,cost,dp),cost[n-2]+helper(n-2,cost,dp)); // return the min of cost to reach step n-1 to top.
                                                                                         // and min of cost to reach n-2 to top.
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return helper(n,cost,dp);
    }
};

tips:
    1. we have to find min 
    2. we are standing at the top , either we can get to the top by step 1 , (n-1) take cost of this step to top
    3. or we can get to the top by step 2 (n-2) take cost of this step to the top
    4. compare and return the min out of it.
    5. similarly to get to the step (n-1) and (n-2) we again have two choices we find the min cost to reach both
    6. and as we move down.