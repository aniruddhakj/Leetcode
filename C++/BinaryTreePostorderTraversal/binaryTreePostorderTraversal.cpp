// Author : Aniruddha Krishna Jha
// Date : 23/04/2022

/*******************************************************************************
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [3,2,1]

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
    void postorderHelper(TreeNode* root, vector<int>& nodes){
        if(!root)
            return;
        postorderHelper(root->left, nodes);
        postorderHelper(root->right, nodes);
        nodes.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodeVals;
        postorderHelper(root, nodeVals);
        return nodeVals;
    }
};
