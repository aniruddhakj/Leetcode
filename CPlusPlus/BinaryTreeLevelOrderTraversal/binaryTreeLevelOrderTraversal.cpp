// Author : Aniruddha Krishna Jha
// Date : 24/04/2022

/*******************************************************************************

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> levelQ;
        vector<int> curLevel; // maintains nodes of current level
        levelQ.push(root);
        levelQ.push(nullptr);
        while(!levelQ.empty()){
            TreeNode* temp = levelQ.front();
            levelQ.pop();
            if(temp){
                curLevel.push_back(temp->val);
   
                if(temp->left)
                    levelQ.push(temp->left);
                if(temp->right)
                    levelQ.push(temp->right);
            }
            else{
                res.push_back(curLevel);
                curLevel.resize(0);
                if(levelQ.size() > 0)
                    levelQ.push(nullptr);
            }
        }
        return res;
    }
};
