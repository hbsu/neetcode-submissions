//need node object
class Node {
    public:
    int value;
    int key;
    Node* next;
    Node* prev;
    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    //need initialization code
    //need private fields
    //need insert/remove functions
private: 

    int cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void insert(Node* node){
        Node* prevNode = head->prev;
        prevNode->next = node;
        node->prev = prevNode;
        node->next = head;
        head->prev = node;
    }

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        head = new Node(0,0);
        tail = new Node(0,0);
        head->prev = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        } 
        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);
        if(cache.size() > cap) {
            Node* leastRecentlyUsed = tail->next;
            remove(leastRecentlyUsed);
            cache.erase(leastRecentlyUsed->key);
            delete leastRecentlyUsed;
        }
        
    }
};
