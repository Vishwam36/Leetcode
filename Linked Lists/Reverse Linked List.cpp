// By Vishwam Shriram Mundada
// https://leetcode.com/problems/reverse-linked-list/
// Easy, recursive approach is tricky

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Constraints:
    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

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
    // recursive approach
    ListNode* rec(ListNode* curr)
    {
        if(curr == NULL || curr -> next == NULL)
            return curr;
        
        ListNode* rest = rec(curr -> next);
        curr -> next -> next = curr;
        
        // tricky step
        curr -> next = NULL;
        
        return rest;
    }
    
    ListNode* reverseList(ListNode* head) 
    {
        return rec(head);
        
        // iterative approach
        ListNode *pre = NULL, *curr = head, *post = head;
        
        while(curr != NULL)
        {
            post = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = post;
        }
        
        return pre;
    }
};
