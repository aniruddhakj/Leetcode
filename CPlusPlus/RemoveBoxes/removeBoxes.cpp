// Author : Aniruddha Krishna Jha
// Date : 14/08/2021

/*******************************************************************************
You are given several boxes with different colors represented by different positive numbers.

You may experience several rounds to remove boxes until there is no box left. 
Each time you can choose some continuous boxes with the same color 
(i.e., composed of k boxes, k >= 1), remove them and get k * k points.

Return the maximum points you can get.
*******************************************************************************/

class Solution {
public:
    int dp(vector<int>& boxes, int i, int j, int k, int dynarray[100][100][100])
    {
        // [i, j] is the operating closed interval
        // k is the number of adjacent boxes on the left of boxes[i] with the same value
        if (i>j) return 0;
        if (dynarray[i][j][k]>0) return dynarray[i][j][k];
        // start with boxes[i] and interval [i+1, j]
        int result = (k+1) * (k+1) + dp(boxes, i+1, j, 0, dynarray);
        for (int m = i + 1; m <= j; m++)
        {
            // if boxes[i]==boxes[m], we can thus eliminate interval [i+1, m-1]
            // to make boxes[i] and boxes[m] adjacent to have a higher score
            if (boxes[i]==boxes[m])
                // if boxes[i] and boxes[m] are adjacent, then
                // there will be k+1 boxes on the left of boxes[m] with the same value
                result = max( result, dp(boxes, i+1, m-1, 0, dynarray) + dp(boxes, m, j, k+1, dynarray) );
        }
        dynarray[i][j][k] = res;
        return result;
    }
    int removeBoxes(vector<int>& boxes)
    {
        int dyboxes[100][100][100] = {0}; 
        int n = boxes.size();
        return dp(boxes, 0, n-1, 0, dyboxes);   // in the closed interval [0, n-1]
    }
};
