class SORTracker {
    // tc - O(log n) for add and O(1) for insert
    // sc - O(n) for set
private:
    // first element in set is the most -ve (having higher score)
    set<pair<int, string>> s;
    // will always be pointing to the last element in set
    set<pair<int, string>> :: iterator it = end(s);
public:    
    void add(string name, int score) {
        // returns an iterator pointing to the score of the added location
        auto it1 = s.insert({ -1*score, name }).first;
        // if it is at the last element or lexicographically larger element, decrease it
        if(it == end(s) or *it1 < *it)
            --it;
    }
    string get() {
        // it should be at the lexicographically smaller location
        return (it++)->second;
    }
};