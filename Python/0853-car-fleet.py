# Author   : Aniruddha Krishna Jha
# Date     : 06/07/2023
# Link     : https://leetcode.com/problems/car-fleet/

'''*******************************************************************************

*******************************************************************************'''

class Solution:
    '''
    Counter to store number of fleets

    Time Complexity  : O(nlogn) for sorting + O(n) for loop = O(nlogn)
    Space Complexity : O(n)
    '''
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pair = [(p, s) for p, s in zip(position, speed)]
        pair.sort(reverse = True)
        fleets = currTimeToReach = 0
        for p, s in pair:
            timeToReach = (target - p)/ s
            if timeToReach > currTimeToReach:
                fleets += 1
                currTimeToReach = timeToReach
        return fleets
