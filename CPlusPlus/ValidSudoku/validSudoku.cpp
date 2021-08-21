// Author : Aniruddha Krishna Jha   
// Date   : 21/08/2021

/********************************************************************************** 
Determine if a 9 x 9 Sudoku board is valid.
Only the filled cells need to be validated according to the following rules:

* Each row must contain the digits 1-9 without repetition.
* Each column must contain the digits 1-9 without repetition.
* Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

* A Sudoku board (partially filled) could be valid but is not necessarily solvable.
* Only the filled cells need to be validated according to the mentioned rules.               
**********************************************************************************/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        const int cnt = 9;
        bool row_mask[cnt][cnt] = {false};
        bool col_mask[cnt][cnt] = {false};
        bool area_mask[cnt][cnt] = {false};
        //check each rows and cols
        for(int r=0; r<board.size(); r++){
            for (int c=0; c<board[r].size(); c++){
                if (!isdigit(board[r][c])) continue;
                int index =  board[r][c] - '0' - 1;
                
                //check the rows
                if (row_mask[r][index] == true){
                    return false;
                }
                row_mask[r][index] = true;
                
                //check the cols
                if (col_mask[c][index] == true) {
                    return false;
                }
                col_mask[c][index] = true;
                
                //check the areas
                int area = (r/3) * 3 + (c/3);
                if (area_mask[area][index] == true) {
                    return false;
                }
                area_mask[area][index] = true;
            }
        }
        
        return true;
    }
};