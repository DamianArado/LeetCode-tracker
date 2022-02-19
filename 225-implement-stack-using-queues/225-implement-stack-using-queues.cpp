class MyStack {
    deque<int> que;
public:
    MyStack() {
    }
    
    void push(int x) {
        que.push_back(x);
    }
    
    int pop() {
        int val = que.back();
        que.pop_back();
        return val;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
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