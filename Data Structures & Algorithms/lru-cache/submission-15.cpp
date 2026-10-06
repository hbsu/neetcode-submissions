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
    int cap;
    unordered_map<int, Node* >cache;
    Node* left; //tail / least recently used
    Node* right; //head / most recently used

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insert(Node* node) {
        // inserting script means setting node->next = right and our prev = right-prev
        Node* prevNode = right->prev;
        node->next = right;
        right->prev = node;
        node->prev = prevNode;
        prevNode->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear(); //initialize with zero
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        remove(node); //remove it from thing
        insert(node); //now it bcomes MRU
        return node->val;   
    }
    
    void put(int key, int value) {
        //if already exists in cache, remove the cache spot.
        if(cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);
        //If capacity too big
        if(cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
        
    }
};
