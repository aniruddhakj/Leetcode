# Author    : Aniruddha Krishna Jha
# Date      : 10/07/2023
# Link      : https://leetcode.com/problems/koko-eating-bananas/

'''*******************************************************************************
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. 
Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.


Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
*******************************************************************************'''

class Solution:
    '''
    Binary search-> search for the minimum k

    Time Complexity: O(nlogn)
    Space Complexity: O(1)
    '''
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        res = max(piles) # worst case

        while l < r:
            k = (l + r) // 2
            time = 0

            for pile in piles:
                time += math.ceil(pile / k) # calculate time taken for each pile on current speed k
            if time > h:
                l = k + 1
            else:
                res = min(res, k)
                r = k
        return res
    