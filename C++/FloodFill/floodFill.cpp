// Author : Aniruddha Krishna Jha
// Date : 14/10/2022

/*******************************************************************************
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. 
You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, 
plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. 
Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

Example:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), 
all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
*******************************************************************************/

//INTUITION: Flood filling requires all 4-connected pixels to be same value
//We can use a dfs? to find connected components(same pixels)across all 4 directions

class Solution {
public:
    
    void dfs(vector<vector<int>> &img, int i, int j, int &clr, int &val){
        //boundary conditions for coordinates
        if(i < 0 || i >= img.size() || j < 0 || j >= img[0].size()) return;
        
        //pixel is already filled or pixel is not connected
        if(img[i][j] == clr || img[i][j] != val) return;
        
        img[i][j] = clr; //fill with new color
        
        
        //move all four directions
        dfs(img, i+1, j, clr, val);
        dfs(img, i, j+1, clr, val);
        dfs(img, i-1, j, clr, val);
        dfs(img, i, j-1, clr, val);
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int cur = image[sr][sc]; //store the current val;
        dfs(image, sr, sc, color, cur);
        return image;
    }
};
