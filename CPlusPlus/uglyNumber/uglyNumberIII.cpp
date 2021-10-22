// Author : Aniruddha Krishna Jha   
// Date   : 22/10/2021

/********************************************************************************** 
An ugly number is a positive integer that is divisible by a, b, or c.

Given four integers n, a, b, and c, return the nth ugly number.

Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
**********************************************************************************/


class Solution {
public:
    long long lcm(long long a, long long b){
        return a*b/__gcd(a, b);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long num=n, aa = a, bb = b, cc = c, low = 0, high = INT_MAX, val=0;
        while(low<=high){
            long long mid=(low + high)/2;
            val = (mid/aa) + (mid/bb) + (mid/cc) - (mid/lcm(aa,bb)) - (mid/lcm(bb,cc)) - (mid/lcm(aa,cc)) + (mid/lcm(aa,lcm(bb,cc)));
            if(val < n)
                low = mid + 1;
            else
                high = mid - 1;   
        }
        return low;    
    }
};