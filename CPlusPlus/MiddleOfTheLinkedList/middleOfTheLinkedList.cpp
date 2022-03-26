// Author : Aniruddha Krishna Jha
// Date : 26/03/2022

/*******************************************************************************
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example :
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
*******************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        //fast moves two steps for every one step by slow
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //as fast reaches the end, slow should be at mid
        return slow;
    }
};
