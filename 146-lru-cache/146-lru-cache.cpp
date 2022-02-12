class LRUCache {
public:
    int capacity, size;
    unordered_map<int, int> m;  // store key-value pairs
    list<int> dll;  // differentiate between least-recently used and most-recently used
    unordered_map<int, list<int>::iterator> addrOfNode;
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        // delete the key-value pair from map and list
        list<int> :: iterator it = addrOfNode[key];
        dll.erase(it);
        addrOfNode.erase(key);
        // put the key at the front of DLL (most-recently used)
        dll.emplace_front(key);
        // add address of this node in map
        addrOfNode[key] = dll.begin();
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            // delete the key-value pair from list and map if its there in map already
            dll.erase(addrOfNode[key]);
            addrOfNode.erase(key);
            m.erase(key);
            size--;
        }
        // update (add) the key-value pair in map and list
        if(size == capacity) {
            // delete the least-recently used 
            int lruKey = dll.back();
            dll.pop_back();
            m.erase(lruKey);
            addrOfNode.erase(lruKey);
            size--;
        }
        m[key] = value;
        dll.emplace_front(key);
        addrOfNode[key] = dll.begin();
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */