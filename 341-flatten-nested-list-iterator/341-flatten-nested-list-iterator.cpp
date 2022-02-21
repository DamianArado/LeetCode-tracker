/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    void makeFlat(NestedInteger x) {
        if (x.isInteger()) {
            flat.emplace_back(x.getInteger());
        }
        else {
            for (auto y : x.getList())
                makeFlat(y);
        }
    }
    
    vector<int> flat;
    int i = 0;    

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto x : nestedList) {
            makeFlat(x);
        }
    }
    
    int next() {
        return flat[i++];
    }
    
    bool hasNext() {
        return i < flat.size();
    }
    
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */