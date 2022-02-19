class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {

    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (st1.empty()) return -1;
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int a = st2.top();
        st2.pop();
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return a;
    }

    int peek() {
        if (st1.empty()) return -1;
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int a = st2.top();
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return a;
    }

    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */