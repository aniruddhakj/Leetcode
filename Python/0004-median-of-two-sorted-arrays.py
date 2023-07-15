# Author    : Aniruddha Krishna Jha
# Date      : 15/07/2023
# Link      : https://leetcode.com/problem/median-of-two-sorted-arrays/

'''*******************************************************************************
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*******************************************************************************'''

class Solution:
    '''
    Binary Search -> partition both arrays and such that the left part of both arrays is smaller than the right part
    calculate median based on (max(left partitions) + min(right partitions))/2 or max(left) (if odd number of elements)

    Time Complexity: O(log(min(m,n)))
    Space Complexity: O(1)
    '''
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        A, B = nums1, nums2
        total = len(A) + len(B)
        half = total // 2

        if len(A) > len(B):
            A, B = B, A

        l, r = 0, len(A) - 1
        while True:
            i = (l + r) // 2 # partition of A
            j = half - i - 2 # partition of B

            Aleft = A[i] if i >= 0 else float("-infinity")
            Aright = A[i + 1] if (i + 1) < len(A) else float("infinity")
            Bleft = B[j] if j >= 0 else float("-infinity")
            Bright = B[j + 1] if (j + 1) < len(B) else float("infinity")

            # if this is the correct partition
            if Aleft <= Bright and Bleft <= Aright:
                # even number of elements
                if total % 2 == 0:
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
                # odd number of elements
                else:
                    return min(Aright, Bright)
                
            elif Aleft > Bright:
                r = i - 1
            else:
                l = i + 1