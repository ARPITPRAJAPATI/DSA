78. Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

solution

class Solution {
public:
    void helper(int i,vector<int>& temp,vector<int>& nums,vector<vector<int>>&result){
        if(i>=nums.size()){
            result.push_back(temp);  // at the end of tree just add the temp in result
            return;
        }

        temp.push_back(nums[i]); //take the element in the temp
        helper(i+1,temp,nums,result); // and move down
        temp.pop_back(); // pop the element to move without it 
        helper(i+1,temp,nums,result); // move without the element 
    }

    vector<vector<int>> subsets(vector<int>& nums) {
       
       vector<int>temp; // to store temp 
       vector<vector<int>>result;  // to result 
       helper(0,temp,nums,result); //call helper
       return result; // update result from helper and return it 
    }
};

tips.. 1. make a tree before solving this 
       2. take or skip two recusrions
       3. we get the element at the end of the tree 
       4. first store in temp
       5. then store the temp in result (use helper function for updating result) 