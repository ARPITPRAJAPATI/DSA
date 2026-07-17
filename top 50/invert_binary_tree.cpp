


solution:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr; // base condition 
        }
        TreeNode* l= invertTree(root -> left); // till the left //store node
        TreeNode* r = invertTree(root -> right); // till the right //store node
        root -> left = r; //left to right
        root -> right = l; // right to left 
        return root; // return the root after swap so get root
    }
};