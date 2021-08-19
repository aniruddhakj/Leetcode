# Author : Aniruddha Krishna Jha
# Date : 19/08/2021

'''*******************************************************************************
Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.
Example 1:

Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110

Example 2:

Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6
*******************************************************************************'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: TreeNode) -> int:
        total = self._dfs_sum(root)
        self.max_product = 0
        self._dfs_product(root, total)
        return self.max_product % (10 ** 9 + 7)

    def _dfs_sum(self, node):
        if node is None:
            return 0
        return self._dfs_sum(node.left) + self._dfs_sum(node.right) + node.val

    def _dfs_product(self, node, total):
        if node is None:
            return 0
        l = self._dfs_product(node.left, total)
        r = self._dfs_product(node.right, total)
        s = l + r + node.val
        product = (total - s) * s
        self.max_product = max(self.max_product, product)
        return s
