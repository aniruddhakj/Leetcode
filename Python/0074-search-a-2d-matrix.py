# Author    : Aniruddha Krishna Jha
# Date      : 10/07/2023
# Link      : https://leetcode.com/problems/search-a-2d-matrix/

'''*******************************************************************************
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*******************************************************************************'''

class Solution:
    '''
    Binary search on a 2D matrix -> convert to 1D array & then binary search
    Convert to 1D array -> matrix[mid // m][mid % m] where m = columns in matrix
    
    Time Complexity: O(logn)
    Space Complexity: O(1)
    '''
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n, m = len(matrix), len(matrix[0])
        l, r = 0, n * m - 1
        while l != r:
            mid = (l + r) // 2
            if matrix[mid // m][mid % m] < target: 
                l = mid + 1
            else:
                r = mid
        return matrix[r // m][r % m] == target