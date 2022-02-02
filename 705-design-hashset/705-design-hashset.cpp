class MyHashSet {
public:
    int sz;
    vector<list<int>> m;
    MyHashSet() {
        sz = 100;
        m.resize(sz);
    }
    
    int hash(int key) {
        return ((key) % (sz));
    }
    
    list<int> :: iterator search(int key) {
        int idx = hash(key);
        return find(m[idx].begin(), m[idx].end(), key);
    }
    
    bool contains(int key) {
        int idx = hash(key);
        if(search(key) == m[idx].end()) return false;
        return true;
    }
    
    void add(int key) {
        if(contains(key)) return;
        int idx = hash(key);
        m[idx].emplace_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int idx = hash(key);
        m[idx].erase(search(key));
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */