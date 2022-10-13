// Author : Aniruddha Krishna Jha
// Date : 24/04/2022

/*******************************************************************************
You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
Return the root node of the BST after the insertion. 
It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. 
You can return any of them.
 
Example:

Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        TreeNode* curr = root;
        
        while(1){
            if(curr->val > val){
                if(curr->left)
                    curr = curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->right)
                    curr = curr->right;
                else{
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
