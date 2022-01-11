// By Vishwam Shriram Mundada
// https://leetcode.com/problems/split-linked-list-in-parts/
// Easy

/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

Example 1:
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example 2:
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.

Constraints:
    The number of nodes in the list is in the range [0, 1000].
    0 <= Node.val <= 1000
    1 <= k <= 50
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
            head = head->next;
            l++;
        }
        return l;
    }
    
    ListNode* newNode(int x)
    {
        ListNode* t = new ListNode();
        t->val = x;
        return t;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        vector<ListNode*> ans;
        ListNode* temp;
        ListNode* t = head;
        int len = length(head);
        
        while(t)
        {
            int req;
            if(len % k == 0)
                req = len/k;
            else
                req = len/k + 1;
            
            k--;
            len -= req;
            
            temp = newNode(-1);
            ListNode* start = temp;
            while(t && req--)
            {
                temp->next = newNode(t->val);
                t = t->next;
                temp = temp->next;
            }
            
            ans.push_back(start->next);
        }
        
        while(k--)
            ans.push_back(NULL);
        
        return ans;
    }
};
