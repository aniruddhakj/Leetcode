// Author : Aniruddha Krishna Jha
// Date : 03/04/2022

/*******************************************************************************
You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. 
You need to merge the two trees into a new binary tree. 
The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. 
Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.

Example:
Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return nullptr;
        TreeNode* root = new TreeNode((root1? root1->val: 0) + (root2 ? root2->val:0));
        // Recursive calls to add the NOT NULL values to the new trees left and right branch
        root->left = mergeTrees(root1? root1->left: nullptr, root2? root2->left: nullptr);
        root->right = mergeTrees(root1? root1->right: nullptr, root2? root2->right: nullptr);               
        return root;
    }
};
