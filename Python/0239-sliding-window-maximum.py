# Author   : Aniruddha Krishna Jha
# Date     : 05/07/2023
# Link     : https://leetcode.com/problems/sliding-window-maximum/


'''*******************************************************************************
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*******************************************************************************'''

class Solution:
    '''
    Sliding window with deque -> deque stores the indices of the elements in the window
    the first element of the deque is the index of the largest element in the window

    Time Complexity: O(n)
    Space Complexity: O(k) -> deque size
    '''
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        dq = collections.deque() # for the indices
        l = r = 0

        while r < len(nums):
            # no need for smaller values
            while dq and nums[dq[-1]] < nums[r]:
                dq.pop()
            dq.append(r)

            # remove left if it's out of window
            if l > dq[0]:
                dq.popleft()

            # if window size is reached update the result and move the window
            if (r + 1) >= k:
                res.append(nums[dq[0]])
                l +=1 
            r += 1
        return res
            
