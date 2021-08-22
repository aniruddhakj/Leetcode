# Author : Aniruddha Krishna Jha
# Date : 22/08/2021

'''*******************************************************************************
We are given a list of (axis-aligned) rectangles. 
Each rectangle[i] = [xi1, yi1, xi2, yi2] , 
where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of the top-right corner of the ith rectangle.

Find the total area covered by all rectangles in the plane. Since the answer may be too large, return it modulo 109 + 7.
*******************************************************************************'''
class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        N = len(rectangles)
        x_vals, y_vals = set(), set()
        for x1, y1, x2, y2 in rectangles:
            x_vals.add(x1)
            x_vals.add(x2)
            y_vals.add(y1)
            y_vals.add(y2)

        imapx = sorted(x_vals)
        imapy = sorted(y_vals)
        mapx = {x: i for i, x in enumerate(imapx)}
        mapy = {y: i for i, y in enumerate(imapy)}

        grid = [[0] * len(imapy) for _ in imapx]
        for x1, y1, x2, y2 in rectangles:
            for x in range(mapx[x1], mapx[x2]):
                for y in range(mapy[y1], mapy[y2]):
                    grid[x][y] = 1

        ans = 0
        for x, row in enumerate(grid):
            for y, val in enumerate(row):
                if val:
                    ans += (imapx[x+1] - imapx[x]) * (imapy[y+1] - imapy[y])
        return ans % (10**9 + 7)