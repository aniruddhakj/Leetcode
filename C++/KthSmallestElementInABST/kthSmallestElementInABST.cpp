// Author : Aniruddha Krishna Jha
// Date : 18/04/2022

/*******************************************************************************
Given the root of a binary search tree, and an integer k, 
return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
 
Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
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
    int count = 0;
    int result = INT_MIN;
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return result;
    }
    void helper(TreeNode* root, int k){
        if(!root)
            return;
        // move to left increment count after every visited node
        helper(root->left, k);
        count++;
        if(count == k)
            result = root->val;
        helper(root->right, k);
    }
};
