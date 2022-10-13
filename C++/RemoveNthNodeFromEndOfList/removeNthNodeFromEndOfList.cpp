// Author : Aniruddha Krishna Jha
// Date : 26/03/2022

/*******************************************************************************
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        if(!fast)
            return head->next;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
            //between fast and slow lies the nth node
        }
        //sever connection
        slow->next = slow->next->next;
        return head;
    }
};
