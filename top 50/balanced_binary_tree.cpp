Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

Input: root = [3,9,20,null,null,15,7]
Output: true



Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Input: root = []
Output: true
 

solution:
,
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    int helper(int& valid ,TreeNode* root){
        if(root==nullptr){
            return 0; // return 0 for base
        }
        
        int l =  helper( valid , root -> left); // go till left
        int r =  helper( valid , root -> right); // go till right
        if(abs(l-r)>1){
            valid = 0;  // if anyhow -1<=hight<=1 voilate this 
            return 0; // will return 0  and change valid to 0 
        }
        return 1+max(l,r); // return the height of the max from l to r 
    }
    bool isBalanced(TreeNode* root) {
        int valid = 1;
        helper(valid,root);
        if(!valid){
            return false;
        }
        return true;
    }
};

tips : take a helper function 
return the height for that 
