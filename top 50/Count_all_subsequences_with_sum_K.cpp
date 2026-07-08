Count all subsequences with sum K

Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.


Example 1

Input : nums = [4, 9, 2, 5, 1] , k = 10

Output : 2

Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].


solution

class Solution{
    public: 

    void helper(int i,vector<int>& nums,int& count,int k){ // take value by refrence 
        if(i == nums.size()){
            if(k==0){
            count++;           // at base if the k == 0 increase count
           }
           return;
        }
        
        helper(i+1,nums,count,k-nums[i]);  // include and decrease k
        helper(i+1,nums,count,k);     // not include 
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	int count =0;
        helper(0,nums,count,k);
        return count;        // return count after update from helper
    }
};


tips... 1. Take a count this will help to return the  value;
        2. decrease the k in include element
        3. traverse the tree till last and all 
        the values which we get in the last is answes.
        4. if value is equall to k count++