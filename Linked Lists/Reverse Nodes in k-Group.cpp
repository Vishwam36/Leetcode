// By Vishwam Shriram Mundada
// https://leetcode.com/problems/reverse-nodes-in-k-group/
// Good

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
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre, *curr = head, *post = curr->next;
        while(curr)
        {
            curr->next = pre;
            pre = curr;
            curr = post;
            if(curr)
                post = curr->next;
        }
        return pre;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* pre, *curr = head, *t = head, *ans = NULL, *preLast = NULL;
        while(t)
        {
            int kk = k;
            curr = t;
            while(t && kk--)
            {
                pre = t;
                t = t->next;
            }
            
            if(kk > 0)
                break;
                        
            pre->next = NULL;
            pre = reverse(curr);
            if(preLast)
                preLast->next = pre;
            
            if(!ans)
                ans = pre;
            
            curr->next = t;
            preLast = curr;
        }
        return ans;
    }
};
