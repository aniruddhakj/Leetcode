// Author : Aniruddha Krishna Jha
// Date : 24/03/2022

/*******************************************************************************
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. 
Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

Example :

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
*******************************************************************************/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1, count = 0;
        while(i <= j)
        {
            if(people[i] + people[j] <= limit)
            {
                i++;
                j--;
                count++;
            }
            else
            {
                j--;
                count++;
            }
        }
        return count;
    }
};
