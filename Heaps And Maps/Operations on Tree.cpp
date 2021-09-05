// By Vishwam Shriram Mundada
// https://leetcode.com/problems/operations-on-tree/
// Lengthy implementation

/*
You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of the ith node. The root of the tree is node 0,
so parent[0] = -1 since it has no parent. You want to design a data structure that allows users to lock, unlock, and upgrade nodes in the tree.

The data structure should support the following functions:

    Lock: Locks the given node for the given user and prevents other users from locking the same node. You may only lock a node if the node is unlocked.
	
    Unlock: Unlocks the given node for the given user. You may only unlock a node if it is currently locked by the same user.
	
    Upgrade: Locks the given node for the given user and unlocks all of its descendants. You may only upgrade a node if all 3 conditions are true:
        The node is unlocked,
        It has at least one locked descendant (by any user), and
        It does not have any locked ancestors.

Implement the LockingTree class:

    LockingTree(int[] parent) initializes the data structure with the parent array.
    lock(int num, int user) returns true if it is possible for the user with id user to lock the node num, or false otherwise. If it is possible, the node num will become 
	locked by the user with id user.
    unlock(int num, int user) returns true if it is possible for the user with id user to unlock the node num, or false otherwise. If it is possible, the node num will 
	become unlocked.
    upgrade(int num, int user) returns true if it is possible for the user with id user to upgrade the node num, or false otherwise. If it is possible, the node num will be 
	upgraded.

Example 1:

Input
["LockingTree", "lock", "unlock", "unlock", "lock", "upgrade", "lock"]
[[[-1, 0, 0, 1, 1, 2, 2]], [2, 2], [2, 3], [2, 2], [4, 5], [0, 1], [0, 1]]
Output
[null, true, false, true, true, true, false]

Explanation
LockingTree lockingTree = new LockingTree([-1, 0, 0, 1, 1, 2, 2]);
lockingTree.lock(2, 2);    // return true because node 2 is unlocked.
                           // Node 2 will now be locked by user 2.
lockingTree.unlock(2, 3);  // return false because user 3 cannot unlock a node locked by user 2.
lockingTree.unlock(2, 2);  // return true because node 2 was previously locked by user 2.
                           // Node 2 will now be unlocked.
lockingTree.lock(4, 5);    // return true because node 4 is unlocked.
                           // Node 4 will now be locked by user 5.
lockingTree.upgrade(0, 1); // return true because node 0 is unlocked and has at least one locked descendant (node 4).
                           // Node 0 will now be locked by user 1 and node 4 will now be unlocked.
lockingTree.lock(0, 1);    // return false because node 0 is already locked.

Constraints:
    n == parent.length
    2 <= n <= 2000
    0 <= parent[i] <= n - 1 for i != 0
    parent[0] == -1
    0 <= num <= n - 1
    1 <= user <= 104
    parent represents a valid tree.
    At most 2000 calls in total will be made to lock, unlock, and upgrade.
*/

class LockingTree {
public:
    int n;
    vector<int> parent;
    vector<vector<int> > children;
    unordered_map<int, int> node_user;
    unordered_map<int, unordered_set<int> > user_node;
    
    LockingTree(vector<int>& parent) {
        n = parent.size();
        this->parent = parent;
        
        children = vector<vector<int> >(n);
        for(int i = 1; i < n; ++i)
            children[parent[i]].push_back(i);
        
        for(int i = 0; i < n; ++i)
            node_user[i] = -1;
    }
    
    bool lock(int num, int user) {
        if(node_user[num] != -1)
            return false;
        
        node_user[num] = user;
        user_node[user].insert(num);
        return true;
    }
    
    bool unlock(int num, int user) {
        if(user_node[user].find(num) == user_node[user].end())
            return false;
        
        user_node[user].erase(num);
        node_user[num] = -1;
        return true;
    }
    
    bool upgrade(int num, int user) {
        if(node_user[num] != -1)
            return false;
        
        bool ans = false;
        for(auto child : children[num])
            if(checkDecLock(child))
                ans = true;
        
        if(ans == false)
            return false;
        
        if(checkAncLock(parent[num]))
            return false;
        
        user_node[user].insert(num);
        node_user[num] = user;
        
        for(auto child : children[num])
            unlockDec(child);
        
        return true;
    }
    
    void unlockDec(int num)
    {
        if(num >= n)
            return;
        
        if(node_user[num] != -1)
        {
            user_node[node_user[num]].erase(num);
            node_user[num] = -1;
        }
        
        for(auto child : children[num])
            unlockDec(child);
    }
    
    bool checkDecLock(int num)
    {
        if(num >= n)
            return false;
        
        if(node_user[num] != -1)
            return true;
                
        for(auto child : children[num])
            if(checkDecLock(child))
                return true;
        
        return false;
    }
    
    bool checkAncLock(int num)
    {
        if(num == -1)
            return false;
        
        if(node_user[num] != -1)
            return true;
        
        if(num == 0)
            return false;
        
        return checkAncLock(parent[num]);
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
