class MyHashMap {
private:
    int sizeMap = 1000;
    vector<list<pair<int, int>>> mp;  // pair: <key, value>
public:
    MyHashMap() {
        mp.resize(sizeMap);
    }
    
    int hash(const int &key) {
        return key % sizeMap;
    }
    
    void put(int key, int value) {
        int index = hash(key);
        auto it = mp[index].begin();
        while (it != mp[index].end()) {
            if (it->first == key) {
                it->second = value;
                return;
            }
            ++it;
        }
        mp[index].emplace_back(key, value);
    }
    
    int get(int key) {
        int index = hash(key);
        auto it = mp[index].begin();
        while (it != mp[index].end()) {
            if (it->first == key)
                return it->second;
            ++it;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        auto it = mp[index].begin();
        while (it != mp[index].end()) {
            if (it->first == key) {
                mp[index].erase(it);
                return;
            }
            ++it;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */