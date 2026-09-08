class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr){}

};

class LRUCache {

private:
    int cap; //capacity
    Node* right; //head
    Node* left; //tail
    unordered_map<int, Node*> cache;

    void insert(Node* node) {
        Node* prevNode = right->prev;
        prevNode->next = node;
        node->prev = prevNode;
        node->next = right;
        right->prev = node;
    }

    void remove(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        cache.clear();
        cap = capacity;
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
        remove(cache[key]);
        insert(cache[key]);
        return node->value;
        
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()){
            Node* newNode = new Node(key, value);
            insert(newNode);
            cache[key] = newNode;
        } else {
            remove(cache[key]);
            Node* newNode = new Node(key, value);
            insert(newNode);
            cache[key] = newNode;
        }
        if(cache.size() > cap){
            Node* lru = left->next;
            remove(left->next);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
