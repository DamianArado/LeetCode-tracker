class MyStack {
private: 
    queue<int> q1, q2;
public:
    // solution 1 will use 2 queues
    // TC: will be defined on each operation separately
    MyStack() {
        
    }
    
    void push(int x) {
        if (!q1.empty() and q2.empty()) q1.push(x);
        q2.push(x);
    }
    
    int pop() {
        int result = -1;
        if (q2.empty()) {
            while (size(q1) > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            result = q1.front();
            q1.pop();
        } else {
            while (size(q2) > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            result = q2.front();
            q2.pop();
        }
        return result;
    }
    
    int top() {
        int result = -1;
        if (q2.empty()) {
            while (size(q1) > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            result = q1.front();
            q2.push(q1.front());
            q1.pop();
        } else {
            while (size(q2) > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            result = q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        return result;
    }
    
    bool empty() {
        return q1.empty() and q2.empty();
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