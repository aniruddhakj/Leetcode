// Author : Aniruddha Krishna Jha
// Date : 24/04/2022

/*******************************************************************************
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
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
    bool symHelper(TreeNode* l, TreeNode* r){
        if(!l && !r)
            return true;
        else if(!l || !r)
            return false;
        else{
            if(l->val != r->val)
                return false;
            return symHelper(l->left, r->right) && symHelper(r->left, l->right);
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return symHelper(root->left, root->right);
    }
};
