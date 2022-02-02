class MyHashMap {
public:
    int sz;
    vector<list<pair<int, int>>> m;
    MyHashMap() {
        sz = 1000;
        m.resize(sz);
    }
    
    int hash(int key) {
        return key % sz;
    }
    
    list<pair<int, int>> :: iterator search(int key) {
        int idx = hash(key);
        list<pair<int, int>> :: iterator it = m[idx].begin();
        while(it != m[idx].end()) {
            if(it->first == key) return it;
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        list<pair<int, int>> :: iterator it = search(key);
        if(it != m[idx].end()) {
            it->second = value;
            return;
        }
        m[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = hash(key);
        list<pair<int, int>> :: iterator it = m[idx].begin();
        while(it != m[idx].end()) {
            if(it->first == key) return it->second;
            it++;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        if(search(key) == m[idx].end()) return;
        m[idx].erase(search(key));
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */