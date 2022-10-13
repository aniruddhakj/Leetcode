// Author : Aniruddha Krishna Jha
// Date : 13/10/2022

/*******************************************************************************
There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.

Example:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
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
