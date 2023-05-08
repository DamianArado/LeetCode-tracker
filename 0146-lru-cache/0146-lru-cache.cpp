// Hardcoded node - maybe a better thing during interviews! It's also faster

class LRUCache {
private:
    class node {
        public:
            int key, value;
            node *prev, *next;
            node(int key, int value) {
                this->key = key;
                this->value = value;
            }
    };
    node *head = new node(-1, -1), *tail = new node(-1, -1);
    int capacity;
    unordered_map<int, node*> m;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node *newNode) {
        node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(node *deletedNode) {
        node *delPrev = deletedNode->prev, *delNext = deletedNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    int get(int key) {
        if(!m.count(key)) return -1;
        node *valNode = m[key];
        int val = valNode->value;
        m.erase(key);
        deleteNode(valNode);
        addNode(valNode);
        m[key] = head->next;
        return val;
    }
    
    void put(int key, int value) {
        if(m.count(key)) {
            node *existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        if(size(m) == this->capacity) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        m[key] = head->next;
    }
};

// class LRUCache {
// private:
//     int capacity;
//     list<int> dll; 
//     unordered_map<int, int> keyValue; // key : value
//     unordered_map<int, list<int>::iterator> keyAddr; // key : address of key
// public:
//     LRUCache(int capacity) {
//         this->capacity = capacity;
//     }
    
//     int get(int key) {
//         if(!keyValue.count(key)) return -1;
        
//         int value = keyValue[key];
//         auto node = keyAddr[key];
//         dll.erase(node);
//         keyAddr.erase(key);
        
//         dll.emplace_front(key);
//         keyAddr[key] = begin(dll);
        
//         return value;
//     }
    
//     void put(int key, int value) {
//         if(keyValue.count(key)) {
//             auto node = keyAddr[key];
//             dll.erase(node);
//             keyAddr.erase(key);
//             keyValue.erase(key);
//         }
//         if(size(keyValue) == this->capacity) {
//             int lru = dll.back();
//             keyAddr.erase(lru);
//             keyValue.erase(lru);
//             dll.pop_back();
//         }
//         dll.emplace_front(key);
//         keyAddr[key] = begin(dll);
//         keyValue[key] = value;
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */