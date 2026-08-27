64. Minimum Path Sum
Solved
Medium
Topics
premium lock icon
Companies
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 Solution:

 class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j!=0) grid[i][j]+=grid[i][j-1];
                if(j==0 and i!=0) grid[i][j]+=grid[i-1][j];
                if(i!=0 and j!=0) grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[n-1][m-1];
    }
};