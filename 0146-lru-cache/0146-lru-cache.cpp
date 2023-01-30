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
        //delete(deletedNode);
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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */