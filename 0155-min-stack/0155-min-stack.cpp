class MinStack {
private:
    vector<pair<int, int>> s;  // < current, min till now >
public:
    MinStack() {}
    
    void push(int val) {
        if(s.empty() or val < s.back().second) s.emplace_back(val, val);
        else s.emplace_back(val, s.back().second);
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return s.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->back();
 * int param_4 = obj->getMin();
 */