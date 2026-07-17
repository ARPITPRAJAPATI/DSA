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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>v; //this will store result
        
        if(root==nullptr){ 
            return v; // if null return result
        }
        q.push(root); // push root in queue

        while(!q.empty()){
            int n = q.size(); // get the size of current level 
            vector<int>temp; // make a temp to store current level ele
            for(int i=0;i<n;i++){
                TreeNode* current =q.front(); //put the front node into curr
                q.pop(); // then pop
                // temp.push_back(current->val);
                if(current->left){ //put his left nto q
                    q.push(current->left);
                }
                if(current->right){ //ut it right into q
                    q.push(current->right);
                }
                 temp.push_back(current->val); // current node val into temp
            }
            v.push_back(temp); // temp into main result
        }
        return v; // return result
    }
};