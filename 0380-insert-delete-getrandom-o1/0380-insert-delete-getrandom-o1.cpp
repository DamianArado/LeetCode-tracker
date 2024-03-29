class RandomizedSet {
private:
    unordered_map<int, int> m;  // [value  -  index]
    vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        bool result = (m.find(val) == m.end());
        v.emplace_back(val);
        m[val] = v.size() - 1;
        return result;
    }
    
    bool remove(int val) {
        bool result = (m.find(val) != m.end());
        if(!result) return result;
        int last = v.back();
        m[last] = m[val];
        v[m[val]] = last;
        v.pop_back();
        m.erase(val);
        return result;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */