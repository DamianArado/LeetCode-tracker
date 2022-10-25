class SmallestInfiniteSet {
private:
    int smallest;
    set<int> st;
public:
    SmallestInfiniteSet() {
        smallest = 1;
    }
    
    int popSmallest() {
        if(st.size()) {
            int first = *st.begin();
            st.erase(first);
            return first;
        }
        smallest += 1;
        return smallest - 1;
    }
    
    void addBack(int num) {
        if(num < smallest)
            st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */