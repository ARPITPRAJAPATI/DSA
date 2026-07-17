235. Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST),

find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that 
has both p and q as descendants (where we allow a node to be a descendant of itself).”

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, 
since a node can be a descendant of itself according to the LCA definition.


solution:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr){
            return nullptr; //base condition
        }

        if(root==p || root==q){
            return root; // if we get the element in left return root
                         // or in right 
        }
        TreeNode* leftN = lowestCommonAncestor( root ->left,  p,  q); //search in the left
        TreeNode* rightN = lowestCommonAncestor( root ->right,  p,  q);

        if(leftN!=nullptr && rightN!=nullptr){
            return root; //if both are not null return root
        }
        if(leftN!=nullptr){
            return leftN ; //return left
        }
        
        return rightN; //return right 
    }
};