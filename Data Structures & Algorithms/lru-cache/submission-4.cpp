class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    private:
    int cap; //top of map
    unordered_map<int, Node*> cache; //int serves as index, and its a map of "nodes" called cache
    Node* left; //left most (least recently used)
    Node* right; //right most (must recently used)

    void remove(Node* node){
        Node* prev = node->prev; //have a pointer point to the previous node
        Node* next = node->next; //have pointer point to next node
        prev->next = next;
        next->prev = prev; //swap nodes
    }

    void insert(Node* node){
        Node* prev = right->prev; //MRU becomes 2nd MRU
        prev->next = node; //make the previous point here
        node->prev = prev; //make our previous pointer to the 2nd MRU
        node->next = right; //we are rightmost (head)
        right->prev = node; //node is MRU

    }

    // Combine hashmap to find a node by its key in O(1)
    // doubly linked list to quickly move nodes from most recently used to least recently used node
    // most recently used on the right side, least recently used on left side
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear(); //clear the cache
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    //if the key is not in the cache, return -1
    //else, remove node from list and insert it on the right 
    //return node value
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        } else {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
    }
    
    //if key already exists, remove old node from list
    //create or update node and store it in cache[key]
    //insert the node near right
    //if len(cache) > capacity:
    //take the node at (left) and remove it, delete its key from hash map
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);
        if(cache.size() > cap) {
            Node* toRemove = left->next;
            remove(toRemove);
            cache.erase(toRemove->key);
            delete toRemove;
        }
    }
};
