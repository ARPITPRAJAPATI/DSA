Count Complete Tree Nodes

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, 
is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible.
 It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

soluton:

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
    int countNodes(TreeNode* root) {
         if (root == nullptr) {
            return 0; // if nothing in tree return 
        }
        int count = 0; 
        queue<TreeNode*>q; // make a queue for nodes
        q.push(root); // push the root into q
        while(!q.empty()){ //if 1 empty 
           
            TreeNode* temp = q.front(); // put the first ele of q into temp
            q.pop(); // then pop from q
            if(temp!=nullptr){
                count++; // if something in temp count++
            } 
            if(temp->left!=nullptr){
                q.push(temp->left); // left of temp push into q
            }
            if(temp->right!=nullptr){
                q.push(temp->right); // right of temp push into q
            }
        }
        return count; // return the count;
    }
};

tips use level order and just count one by one 
using queue;