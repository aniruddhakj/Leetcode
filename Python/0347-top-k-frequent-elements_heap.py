# Author : Aniruddha Krishna Jha   
# Date   : 01/07/2023
# Link   : https://leetcode.com/problems/top-k-frequent-elements/

'''********************************************************************************** 
Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]
**********************************************************************************'''

class Solution:
    '''
    Heap approach
    Time Complexity: O(klogn)
    Space Complexity: O(n) 
    '''
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # create a heap of frequency, num pairs
        heap = []
        heapq.heapify(heap)
        count = {}
        # num -> count mapping
        for num in nums:
            count[num] = 1 + count.get(num, 0)
        # count -> nums mapping
        for num, cnt in count.items():
            heapq.heappush(heap, (-cnt, num))
        print(heap)
        res = []
        for i in range(k):
            res.append(heapq.heappop(heap)[1]) # append the numbers to res
        return res