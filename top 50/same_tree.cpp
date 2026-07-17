100. Same Tree

Given the roots of two binary trees p and q,
write a function to check if they are the same or not.

Two binary trees are considered the same if
 they are structurally identical, and the nodes have the same value.

Input: p = [1,2,3], q = [1,2,3]
Output: true

Input: p = [1,2], q = [1,null,2]
Output: false


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==nullptr && q==nullptr){
            return true; // base case if we get at end return true,
        }                // or both are null
        
        if (p == nullptr || q == nullptr) {
            return false; // if any possible value one is null 
        }                 // other is not null return false 
        if(p->val != q->val){
            return false; // if at a node both notes are not equal return false
        }
        bool left = isSameTree(p->left,q->left);  //move left in pand q
        bool right = isSameTree(q->right,q->right); // move right till the end p and q
        return left&&right; // return the any possible value from both at a root
    }
};

tips .. just compare both trees if any node is not equal return false