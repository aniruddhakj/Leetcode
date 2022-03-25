// Author : Aniruddha Krishna Jha
// Date : 25/03/2022

/*******************************************************************************
A company is planning to interview 2n people. 
Given the array costs where costs[i] = [aCosti, bCosti], 
the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

Example :
Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
*******************************************************************************/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2, minCost = 0;
        vector<int> diff; // maintain the list of savings if flown to B
        for (auto cityCost: costs){
            minCost += cityCost[0]; // Fly all to city A
            diff.push_back(cityCost[1] - cityCost[0]); //push the difference if flown to B 
        }
        sort(diff.begin(), diff.end());
        for(int i = 0; i < n; i++){
            minCost += diff[i]; //n out 2n are flown to B for which saving is max.
        }
        return minCost;
    }
};
