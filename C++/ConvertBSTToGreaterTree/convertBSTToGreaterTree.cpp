// Author : Aniruddha Krishna Jha
// Date : 16/04/2022

/*******************************************************************************
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that 
every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

Example 2:

Input: root = [0,null,1]
Output: [1,null,1]
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
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        convertHelper(root);
        return root;
    }
    void convertHelper(TreeNode* root){
        if(!root)
            return;
        // go all the way right, adding the greater numbers 
        convertHelper(root->right);
        root->val = (sum+= root->val); //replace the current root->val to sum of all greater numbers
        convertHelper(root->left);
    }
};
