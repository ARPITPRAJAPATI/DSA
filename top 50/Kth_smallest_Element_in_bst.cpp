230. Kth Smallest Element in a BST

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:
Input: root = [3,1,4,null,2], k = 1

Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

solution:

class Solution {
public:
    void helper(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return; // using inorder
        }

        helper(root->left, v);
        v.push_back(root->val); // add val in sorted order
        helper(root->right, v);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        helper(root, v);
        return v[k - 1]; // return k-1 index element
    }
};
 



