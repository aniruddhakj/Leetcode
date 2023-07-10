# Author   : Aniruddha Krishna Jha
# Date     : 06/07/2023
# Link     : https://leetcode.com/problems/car-fleet/

'''*******************************************************************************

*******************************************************************************'''

class Solution:
    '''
    Stack -> store (position, speed) in stack and pop when current time to reach <= previous time to reach

    Time Complexity  : O(nlogn) for sorting + O(n) for loop = O(nlogn)
    Space Complexity : O(n) + O(n) for stack and pair = O(n)
    '''
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pair = [(p, s) for p, s in zip(position, speed)]
        pair.sort(reverse = True)
        stack = []
        for p, s in pair:
            stack.append((target - p)/ s) # store time to reach in stack
            if len(stack) >= 2 and stack[-1] <= stack[-2]:
                stack.pop()
        return len(stack)