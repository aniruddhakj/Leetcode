// Author : Aniruddha Krishna Jha
// Date : 19/04/2022

/*******************************************************************************
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure.

Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Example 2:

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
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
    void helper(TreeNode* root, TreeNode* &first, TreeNode* &second, TreeNode* &prev){
        if(!root)
            return;
        helper(root->left, first, second, prev);
        if(prev){
            if(root->val < prev->val){
                if(!first){
                    first = prev;    
                }
                second = root;
            }            
        }
        prev = root;
        helper(root->right, first, second, prev);
    }
    
    void recoverTree(TreeNode* root) {
        //flag, if left greater false, right lesser false
        //swap
        TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
        helper(root, first, second, prev);
        swap(first->val, second->val);
        return;
    }
};
