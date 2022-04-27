// Author : Aniruddha Krishna Jha
// Date : 27/04/2022

/*******************************************************************************
Given the root of a Binary Search Tree and a target number k, 
return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
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
    unordered_set<int> nums;
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        if(nums.find(k - root->val) != nums.end())
            return true;
        nums.insert(root->val);
        return findTarget(root->left, k) or findTarget(root->right, k);
    }
};
