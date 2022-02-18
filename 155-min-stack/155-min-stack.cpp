// TC - O(1) SC - O(n)
class MinStack {
public:
    vector<pair<int, int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()) stk.push_back({val, val});
        else stk.push_back({val, min(stk.back().second, val)});
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */