
/*
146. LRU Cache
Solved
Medium
Topics
premium lock iconCompanies

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

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
    0 <= key <= 104
    0 <= value <= 105
    At most 2 * 105 calls will be made to get and put.

*/
class Node {
public:
    int key, val;
    Node* next;
    Node* prev;

    Node(int k, int v, Node* ne = nullptr, Node* pr = nullptr) {
        key = k;
        val = v;
        next = ne;
        prev = pr;
    }
};

void del(Node* a) {
    if (a->prev) a->prev->next = a->next;
    if (a->next) a->next->prev = a->prev;
}

class LRUCache {
public:
    int n;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        n = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;

        Node* a = mpp[key];
        del(a);

        // Move node to front
        a->next = head->next;
        a->prev = head;
        head->next->prev = a;
        head->next = a;

        return a->val;
    }

    void put(int key, int value) {
        // If key exists, just update and move to front
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;
            del(node);
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            return;
        }

        // If capacity full, remove least recently used node
        if (mpp.size() >= n) {
            Node* lru = tail->prev;
            del(lru);
            mpp.erase(lru->key);
            delete lru;
        }

        // Insert new node at front
        Node* newNode = new Node(key, value, head->next, head);
        head->next->prev = newNode;
        head->next = newNode;
        mpp[key] = newNode;
    }

    ~LRUCache() {
        // Clean up all nodes
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};