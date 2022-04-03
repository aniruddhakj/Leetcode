// Author : Aniruddha Krishna Jha
// Date : 03/04/2022

/*******************************************************************************
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages, such as Java, there is no unsigned integer type. 
In this case, the input will be given as a signed integer type. 
It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. 

Example:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
*******************************************************************************/

class Solution {
public:
    int hammingWeight(uint32_t n) {
		//return 1 when n&n-1 results in non-zero
		//thereby incrementing count by 1 for each 1 bit
        return n ? 1 + hammingWeight(n & (n - 1)) : 0;
    }
};
