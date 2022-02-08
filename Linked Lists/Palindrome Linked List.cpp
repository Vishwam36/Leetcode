// By Vishwam Shriram Mundada
// https://leetcode.com/problems/palindrome-linked-list/
// Decent, with O(N) space its very easy

/*
Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Constraints:
    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space?
*/


// TC : O(N)
// SC : O(N)


/**
 * Algorithm : 
 * reverse second half of LL
 * Check first half and second half for palindrome
 * Again reverse second half to restore original LL
 */

class Solution {
public:
    int len(ListNode* head)
    {
        int l = 0;
        ListNode* t = head;
        while(t)
        {
            t = t->next;
            l++;
        }
        return l;
    }
    
    ListNode* head2;
    ListNode* reverse(ListNode* head)
    {
        if(head->next == NULL)
        {
            head2 = head;
            return head;
        }
        
        ListNode* after = reverse(head->next);
        after->next = head;
        return head;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        if(!head || !head->next)
            return true;
        
        int n = len(head);
        ListNode* t = head, *tail;
        for(int i = 0; i < n/2; ++i)
        {
            tail = t;
            t = t->next;
        }
        tail->next = NULL;
        
        reverse(t)->next = NULL;
        
        bool ans = true;
        ListNode* t1 = head, *t2 = head2;
        while(t1 && t2)
        {
            if(t1->val != t2->val)
                ans = false;
            
            t1 = t1->next;
            t2 = t2->next;
        }
        
        // Restoring original LL
        t = head2;
        reverse(t)->next = NULL;
        tail->next = head2;
        
        return ans;
    }
};
