// Author : Aniruddha Krishna Jha
// Date : 24/04/2022

/*******************************************************************************
Given the root of a binary tree, invert the tree, and return its root.

Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
*******************************************************************************/

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
        if(!root)
            return root;
        queue<TreeNode*> bfsQ;
        bfsQ.push(root);
        
        while(!bfsQ.empty()){
            TreeNode* ptr = bfsQ.front();
            bfsQ.pop();
            
            if(ptr->left)
                bfsQ.push(ptr->left);
            if(ptr->right)
                bfsQ.push(ptr->right);
            swap(ptr->left, ptr->right);
        }
        return root;
    }
};
