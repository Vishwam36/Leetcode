// By Vishwam Shriram Mundada
// https://leetcode.com/problems/copy-list-with-random-pointer/
// Good question, 2 approaches

/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding 
original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied 
list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Constraints:
0 <= n <= 1000
-10000 <= Node.val <= 10000
Node.random is null or is pointing to some node in the linked list.
*/


// App 1 : 
// TC : O(N)
// SC : O(N)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*, Node*> m;
        m[NULL] = NULL;
        Node* temp = head;
        
        while(temp)
        {
            m[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp)
        {
            if(temp->random)
                m[temp]->random = m[temp->random];
            
            m[temp]->next = m[temp->next];
            
            temp = temp->next;
        }
        return m[head];
    }
};


// App 2 :
// TC : O(N)
// SC : O(1). We are just N new nodes and not any extra data structure

// REF : https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43497/2-clean-C%2B%2B-algorithms-without-using-extra-arrayhash-table.-Algorithms-are-explained-step-by-step.

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head)
            return NULL;
        
        Node* l1 = head, *l2;
        
        while(l1)
        {
            l2 = new Node(l1->val);
            l2->next = l1->next;
            l1->next = l2;
            l1 = l1->next->next;
        }
        
        l1 = head;
        
        while(l1)
        {
            l2 = l1->next;
            if(l1->random)
                l2->random = l1->random->next;
            l1 = l1->next->next;
        }
        
        l1 = head;
        Node* newHead = head->next;
        
        while(l1)
        {
            l2 = l1->next;
            l1->next = l2->next;
            if(l1->next)
                l2->next = l1->next->next;
            
            l1 = l1->next;
        }
        
        return newHead;
    }
};
