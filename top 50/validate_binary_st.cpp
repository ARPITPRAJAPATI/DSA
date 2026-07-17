98. Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


solution:

class Solution {
public:
    bool helper(TreeNode* root, long long low, long long high) {
        if (root == nullptr) {
            return true;//base condition
        }
 
        if (root->val <= low || root->val >= high) {
            return false; //if at any possible point in left or right
                          //if less then low or greater than high
                          //return false
        }

        bool isleft = helper(root->left, low, root->val); //move to the left
        bool isright = helper(root->right, root->val, high); //move to right

        return isleft && isright; //any possible val
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);// put in long long 
    }
};