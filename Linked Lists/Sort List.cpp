// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/117/linked-list/840/
// Decent

/*
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:

Input: head = []
Output: []

Constraints:
    The number of nodes in the list is in the range [0, 5 * 104].
    -105 <= Node.val <= 105

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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
    int length(ListNode* head)
    {
        int l = 0;
        while(head)
        {
            l++;
            head = head->next;
        }
        return l;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* t = new ListNode(-1);
        ListNode* h = t;
        
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                t->next = l1;
                l1 = l1->next;
            }
            else
            {
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
        }
        
        while(l1)
        {
            t->next = l1;
            l1 = l1->next;
            t = t->next;
        }
        
        while(l2)
        {
            t->next = l2;
            l2 = l2->next;
            t = t->next;
        }
        
        return h->next;
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        
        int l = length(head);
        ListNode* temp = head, *pre = NULL;
        
        for(int i = 0; i < (l+1)/2; ++i)
        {
            pre = temp;
            temp = temp->next;
        }
        
        pre->next = NULL;
        
        head = sortList(head);
        temp = sortList(temp);
        
        head = merge(head, temp);
        
        return head;
    }
};
