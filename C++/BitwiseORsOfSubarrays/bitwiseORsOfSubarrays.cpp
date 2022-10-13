// Author : Aniruddha Krishna Jha
// Date : 12/10/2022

/*******************************************************************************
We have an array arr of non-negative integers.

For every (contiguous) subarray sub = [arr[i], arr[i + 1], ..., arr[j]] (with i <= j), 
we take the bitwise OR of all the elements in sub, obtaining a result arr[i] | arr[i + 1] | ... | arr[j].

Return the number of possible results. Results that occur more than once are only counted once in the final answer

Example 1:

Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.


Example 2:

Input: arr = [1,1,2]
Output: 3
Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3. 
There are 3 unique values, so the answer is 3.
*******************************************************************************/

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        //OPTIMISATION?? the values are monotonically increasing
        //the result can be stored in a vector just check 
        //if new value is greater than previous
        vector<int> res;
        int l = 0, r;
        
        for(int i: arr){
            r = res.size();
            res.push_back(i);
            for(int j = l; j < r; ++j){
                if(res.back() != (res[j] | i)) res.push_back(res[j] | i);
            }
            
            // update left and right before starting next iteration
            l = r;
        }
        
        //return only distinct values, convert to set and return length?
        return unordered_set(res.begin(), res.end()).size();
    }
};
