// By Vishwam Shriram Mundada
// https://leetcode.com/problems/min-stack/
// App 1 is tricky

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.

Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:
    -231 <= val <= 231 - 1
    Methods pop, top and getMin operations will always be called on non-empty stacks.
    At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

// Tricky approach
// Using single stack
// REF : https://www.youtube.com/watch?v=QMlDCR9xyd8

class MinStack {
public:
    stack<long long> s;
    long long minEle = INT_MAX;
    
    MinStack() {
        
    }
    
    void push(int v) {
        long long val = v;
        if(s.empty())
        {
            minEle = val;
            s.push(val);
        }
        else if(val >= minEle)
        {
            s.push(val);
        }
        else
        {
            s.push(2*val - minEle);
            minEle = val;
        }
    }
    
    void pop() {
        if(s.top() >= minEle)
        {
            s.pop();
        }
        else
        {
            minEle = 2*minEle - s.top();
            s.pop();
        }
    }
    
    int top() {
        if(s.top() >= minEle)
            return s.top();
        else
            return minEle;
    }
    
    int getMin() {
        return minEle;
    }
};


// App 2 : using two stacks 
// Simple

class MinStack {
public:
    stack<int> mins; // for storing minimums
    stack<int> reals; // for storing all values
    
    MinStack() {
        
    }
    
    void push(int val) {
        reals.push(val);
        
        if(mins.empty())
            mins.push(val);
        
        else if(mins.top() >= val)
            mins.push(val);
    }
    
    void pop() {
        if(reals.top() == mins.top())
            mins.pop();
        
        reals.pop();
    }
    
    int top() {
        return reals.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
