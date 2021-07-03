// By Vishwam Shriram Mundada
// https://leetcode.com/problems/lru-cache/
// Decent

/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity 
from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

Constraints:
1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 105 calls will be made to get and put.
*/

// list :: erase() takes O(k) TC where k is no. of elements removed

class LRUCache {
public:
    typedef list<pair<int, int> > :: iterator listItr;
    
    unordered_map<int, listItr> m;
    list<pair<int, int> > l;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        
        int value = (*m[key]).second;
        l.erase(m[key]);
        
        // push key again i.e to show we have accessed it recently
        l.push_back({key, value});
        m[key] = --l.end();
        return value;
    }
    
    void put(int key, int value) {
        if(m.find(key) == m.end()) // no key in list
        {
            if(l.size() < cap)
            {
                l.push_back({key, value});
                m[key] = --l.end(); // point at last node
            }
            else // size full
            {
                m.erase(l.front().first);
                l.pop_front(); // remove LRU
                
                l.push_back({key, value});
                m[key] = --l.end();
            }
        }
        else // key is already present
        {
            l.erase(m[key]);
            
            l.push_back({key, value});
            m[key] = --l.end();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
