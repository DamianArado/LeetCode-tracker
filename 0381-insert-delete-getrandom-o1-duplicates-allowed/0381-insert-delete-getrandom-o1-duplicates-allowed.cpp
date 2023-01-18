class RandomizedCollection {
private:
    unordered_map<int, vector<int>> m;  // [value  - [indices...]]
    vector<pair<int, int>> v;  // [value  -  m[val].size() - 1 (index in map)]
public:
    RandomizedCollection() {}
    
    bool insert(int val) {
        bool result = (m.find(val) == m.end());
        m[val].emplace_back(v.size());
        v.emplace_back(val, m[val].size() - 1);
        return result;
    }
    
    bool remove(int val) {
        bool result = (m.find(val) != m.end());
        if(result) {
            auto last = v.back();
            m[last.first][last.second] = m[val].back();
            v[m[val].back()] = last;
            m[val].pop_back();
            if(m[val].empty()) m.erase(val);
            v.pop_back();
        }
        return result;
    }
    
    int getRandom() {
        return v[rand() % v.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */