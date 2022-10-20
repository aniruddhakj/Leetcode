// Author : Aniruddha Krishna Jha
// Date : 20/10/2022

/*******************************************************************************

*******************************************************************************/

//INTUITION: Simple max heap with stones, y and x at top

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(begin(stones), end(stones));
        
        while(pq.size() > 1){
            int y = pq.top(); 
            pq.pop();
            int x = pq.top();
            pq.pop();
            
            if(x <= y)
                pq.push(y - x);
        }
        // return last remaining stone else 0
        return pq.empty() ? 0 : pq.top();
    }
};
