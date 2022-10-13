// Author : Aniruddha Krishna Jha
// Date : 23/03/2022

/*******************************************************************************
There is a broken calculator that has the integer startValue on its display initially. 
In one operation, you can:

multiply the number on display by 2, or
subtract 1 from the number on display.
Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.

Example :

Input: startValue = 2, target = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
*******************************************************************************/

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int minOps = 0;
        while(target > startValue){
            target = target % 2 == 0? target/2 : target + 1;
            minOps++;
        }
        return minOps + startValue - target;
    }
};
