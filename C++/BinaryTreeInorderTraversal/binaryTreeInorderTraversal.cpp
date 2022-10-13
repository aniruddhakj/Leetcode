// Author : Aniruddha Krishna Jha
// Date : 23/04/2022

/*******************************************************************************
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]
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
     void inorderHelper(TreeNode* root, vector<int>& nodes){
        if(!root)
            return;
        inorderHelper(root->left, nodes);
        nodes.push_back(root->val);
        inorderHelper(root->right, nodes);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodeVals;
        inorderHelper(root, nodeVals);
        return nodeVals;
    }
};
