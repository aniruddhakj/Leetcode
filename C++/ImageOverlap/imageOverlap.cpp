// Author : Aniruddha Krishna Jha
// Date : 26/10/2022

/*******************************************************************************
You are given two images, img1 and img2, represented as binary, square matrices of size n x n. 
A binary matrix has only 0s and 1s as values.

We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. 
We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.

Note also that a translation does not include any kind of rotation. 
Any 1 bits that are translated outside of the matrix borders are erased.

Return the largest possible overlap. 

Example 1:


Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
*******************************************************************************/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        vector<int> a, b;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n * n; ++i)
            if (img1[i / n][i % n]) a.push_back(i / n * 100 + i % n);
        for (int i = 0; i < n * n; ++i)
            if (img2[i / n][i % n]) b.push_back(i / n * 100 + i % n);
        for (int i : a) {
            for (int j : b) cnt[i - j]++;
        }
        int res = 0;
        for (auto &it : cnt) res = max(res, it.second);
        return res;
    }
};
