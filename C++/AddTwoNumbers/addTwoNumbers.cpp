// Author : Aniruddha Krishna Jha
// Date : 02/06/2022

/*******************************************************************************
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example :

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode resultHead(0), *res = &resultHead;
        int carry = 0;
        while(l1 || l2 || carry){
            int curSum = (l1? l1->val:0) + (l2? l2->val:0) + carry;
            res->next = new ListNode(curSum % 10);
            carry = curSum/10;
            res = res->next;
            l1 = l1 ? l1->next: l1; // if l1 has a next move forward 
            l2 = l2 ? l2->next: l2; // if l2 has a next move forward
        }
        return resultHead.next;
    }
};
