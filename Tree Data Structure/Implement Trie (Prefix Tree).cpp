// By Vishwam Shriram Mundada
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/122/design/868/
// Easy

/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:
    Trie() Initializes the trie object.
    void insert(String word) Inserts the string word into the trie.
    boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
    boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

Constraints:
    1 <= word.length, prefix.length <= 2000
    word and prefix consist only of lowercase English letters.
    At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.
*/

class Trie {
public:
    struct TrieNode {
        bool isLeaf;
        TrieNode* children[26];
    };
    
    TrieNode* root = new TrieNode();
    
    Trie() {}
    
    void insert(string word) {
        TrieNode* t = root;
        for(int i = 0; i < word.size(); ++i)
        {
            int idx = word[i]-'a';
            if(!t->children[idx])
                t->children[idx] = new TrieNode();
            
            t = t->children[idx];
        }
        t->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* t = root;
        for(int i = 0; i < word.size(); ++i)
        {
            int idx = word[i]-'a';
            if(!t->children[idx])
                return false;
            
            t = t->children[idx];
        }
        return t->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* t = root;
        for(int i = 0; i < prefix.size(); ++i)
        {
            int idx = prefix[i]-'a';
            if(!t->children[idx])
                return false;
            
            t = t->children[idx];
        }
        return true;
    }
};
