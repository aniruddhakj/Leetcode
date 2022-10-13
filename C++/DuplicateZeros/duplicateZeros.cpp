// Author : Aniruddha Krishna Jha   
// Date   : 20/10/2021

/********************************************************************************** 
Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

* Note that elements beyond the length of the original array are not written. 
* Do the above modifications to the input array in place and do not return anything.   

Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
**********************************************************************************/


class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int length = arr.size();
        int zeroCount = 0;
        for(int i = 0;i < length; ++i){
            if(arr[i] == 0)
                ++zeroCount;
        }
        int j = length + zeroCount;
        for(int i= length - 1 ;i>=0;--i){
            if(--j < length)
                arr[j] = arr[i];
            if(arr[i] == 0 && --j < length)
                arr[j] = 0;
        }
    }
};