# Author    : Aniruddha Krishna Jha   
# Date      : 01/07/2023
# Link      : https://leetcode.com/problems/valid-sudoku/

'''********************************************************************************** 
Determine if a 9 x 9 Sudoku board is valid. 
Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Example :

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
**********************************************************************************'''

class Solution:
    '''
    sets for rows, columns and subboxes
    iterate over the board and check if the element is already present in the current row, col or subbox
    if present return false else add it to the set

    Time Complexity: O(1) since board is always 9x9
    Space Complexity: O(1) since board is always 9x9
    '''
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = collections.defaultdict(set)
        cols = collections.defaultdict(set)
        grid = collections.defaultdict(set)

        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':
                    continue
                # if already found return false
                # check in current row, col and minigrid/ subbox
                if (board[r][c] in rows[r] or 
                    board[r][c] in cols[c] or
                    board[r][c] in grid[(r//3, c//3)]) :
                    return False

                rows[r].add(board[r][c])
                cols[c].add(board[r][c])
                grid[(r//3, c//3)].add(board[r][c]) #Python // -> floor divide
        
        return True