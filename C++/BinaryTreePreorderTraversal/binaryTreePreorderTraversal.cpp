// Author : Aniruddha Krishna Jha
// Date : 23/04/2022

/*******************************************************************************
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,2,3]

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
    void preorderHelper(TreeNode* root, vector<int>& nodes){
        if(!root)
            return;
        nodes.push_back(root->val);
        preorderHelper(root->left, nodes);
        preorderHelper(root->right, nodes);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodeVals;
        preorderHelper(root, nodeVals);
        return nodeVals;
    }
};
