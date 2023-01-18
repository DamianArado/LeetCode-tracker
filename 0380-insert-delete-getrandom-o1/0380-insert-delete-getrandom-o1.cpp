class RandomizedSet {
private:
    unordered_map<int, int> m;  // [value  -  index]
    vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(m.count(val)) return false;
        v.emplace_back(val);
        m[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val)) return false;
        // if val exists at the end
        if(val == v.back()) {
            v.pop_back();
            m.erase(val);
            return true;
        }
        // if not then copy the val to the last element
        int last = v.back();
        m[last] = m[val];
        v[m[val]] = last;
        v.pop_back();
        m.erase(val);
        return true;
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