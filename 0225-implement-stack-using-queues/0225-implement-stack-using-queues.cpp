class MyStack {
private:
    queue<int> stk;
public:
    MyStack() {}
    
    void push(int x) {
        stk.emplace(x);
        for(int i = 0; i < stk.size() - 1; ++i) {
            stk.emplace(stk.front());
            stk.pop();
        }
    }
    
    int pop() {
        int top = stk.front();
        stk.pop();
        return top;
    }
    
    int top() {
        return stk.front();
    }
    
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */