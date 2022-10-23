// Author : Aniruddha Krishna Jha
// Date : 23/10/2022

/*******************************************************************************
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:

Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
*******************************************************************************/

// INTUITION: find middle using fast and slow pointers
// reverse the second half and check for equality

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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *rev = nullptr;
        // find the middle
        while(fast && fast->next) {
            ListNode* tmp = rev;
            fast = fast->next->next;
            rev = slow; 
            slow = slow->next;
            rev->next = tmp;
            
        }
        if(fast) slow = slow->next;
        
        while(rev) {
            if(rev->val != slow->val) return false;
            slow = slow->next;
            rev = rev->next;
        }
        
        return true;
    }
};
