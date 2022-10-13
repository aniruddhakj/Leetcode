// Author : Aniruddha Krishna Jha
// Date : 12/10/2022

/*******************************************************************************
Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).

Example 1:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true

Example 2:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
Output: false
*******************************************************************************/

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
        auto dist =[](auto &p1, auto &p2){ 
            return (p2[0]-p1[0])*(p2[0]-p1[0]) + (p2[1]-p1[1])*(p2[1]-p1[1]); };
        
        vector<vector<int>>pts = {p1, p2, p3, p4};
        set<double> len;
        
        
        for(int i = 0; i < 4; ++i){
            for(int j = i + 1; j < 4; ++j){
                auto curr = dist(pts[i], pts[j]);
                if(curr != 0) len.insert(curr);
                // if length is zero invalid case
                else return false;
            }
        }
        
        // size should have the only distinct elements
        // i.e., a side length & a diagonal length
        return len.size() == 2;
    }
};
