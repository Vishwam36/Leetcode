// By Vishwam Shriram Mundada
// https://leetcode.com/problems/find-median-from-data-stream/
// Good

class MedianFinder {
public:
    // first half minimum elements will be in maxHeap 
    // second half minimum elements will be in minHeap
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    MedianFinder() {}
    
    void addNum(int num) {
        if(maxHeap.empty())
        {
            maxHeap.push(num);
        }
        else if(minHeap.empty())
        {
            if(maxHeap.top() <= num)
                minHeap.push(num);
            else
            {
                minHeap.push(maxHeap.top()); maxHeap.pop();
                maxHeap.push(num);
            }
        }
        else
        {
            if(maxHeap.size() == minHeap.size())
            {
                if(num <= minHeap.top())
                    maxHeap.push(num);
                else
                {
                    maxHeap.push(minHeap.top()); minHeap.pop();
                    minHeap.push(num);
                }
            }
            else
            {
                if(num >= maxHeap.top())
                    minHeap.push(num);
                else
                {
                    minHeap.push(maxHeap.top()); maxHeap.pop();
                    maxHeap.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size())
            return ((double)maxHeap.top() + (double)minHeap.top())/2;
        return (double)maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
