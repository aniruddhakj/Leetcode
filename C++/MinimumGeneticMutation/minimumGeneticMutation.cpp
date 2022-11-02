// Author : Aniruddha Krishna Jha
// Date : 02/11/2022

/*******************************************************************************
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. 
A gene must be in bank to make it a valid gene string.

Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. 
If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

Example 1:

Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1

Example 2:

Input: start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
*******************************************************************************/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        // to remove dupes in bank
        unordered_set<string> st(bank.begin(), bank.end());
        // end string is not in bank set
        if(st.find(end) == st.end()) return -1;
        
        queue<string>q;
        q.push(start);
        
        int mut = 0, sz;
        string cur, tmp;
        while(!q.empty()) {
            sz = q.size();
            while(sz-- ) {
                cur = q.front(); 
                q.pop();    
                
                // found
                if (cur == end) return mut;
                // not found, remove from bankset
                st.erase(cur);
                
                // at each index, replace one char and check for string in bank
                for(int i = 0; i < 8; ++i) {
                    tmp = cur;
                    tmp[i] = 'A';
                    if(st.count(tmp)) q.push(tmp);
                    tmp[i] = 'C';
                    if(st.count(tmp)) q.push(tmp);
                    tmp[i] = 'G';
                    if(st.count(tmp)) q.push(tmp);
                    tmp[i] = 'T';
                    if(st.count(tmp)) q.push(tmp);
                }
                
            }
            ++mut;
        }
        
        return -1;
    }
};
