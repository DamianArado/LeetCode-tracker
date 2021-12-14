class TimeMap {
public:
    TimeMap() {
        
    }
    
    // We use hash map to lookup ordered {timestamp, value} pairs by key in O(1). 
    // Then, we use binary search to find the value with a timestamp less or equal than 
    // the requested one.

    unordered_map<string, map<int, string>> m;
    void set(string key, string value, int timestamp) {
      m[key].insert({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
      auto it = m[key].upper_bound(timestamp);
      return it == m[key].begin() ? "" : prev(it) -> second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */