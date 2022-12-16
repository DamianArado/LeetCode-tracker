/**

Amortized O(1) push, pop & top operations - we will have 2 stacks input & output stack

push - push inside input stack
pop & top - 
if output stack is not empty: output.pop()
else transfer everything from input to output and then output.pop()
empty - input is empty?

*/
class MyQueue {
private:
    stack<int> input, output;
public:
    MyQueue() {}
    
    void push(int x) {
        input.emplace(x);
    }
    
    int pop() {
        int top = -1;
        if(!output.empty()) {
            top = output.top();
            output.pop();
            return top;
        }
        while(!input.empty()) {
            output.emplace(input.top());
            input.pop();
        }
        top = output.top();
        output.pop();
        return top;
    }
    
    int peek() {
        if(!output.empty()) return output.top();
        while(!input.empty()) {
            output.emplace(input.top());
            input.pop();
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() and output.empty();
    }
};

// O(n) time again
// class MyQueue {
// private:
//     stack<int> input, output;
// public:
//     MyQueue() {}
    
//     void push(int x) {
//         while(!output.empty()) {
//             input.emplace(output.top());
//             output.pop();
//         }
//         input.emplace(x);
//     }
    
//     int pop() {
//         while(!input.empty()) {
//             output.emplace(input.top());
//             input.pop();
//         }
//         int x = output.top();
//         output.pop();
//         return x;
//     }
    
//     int peek() {
//         while(!input.empty()) {
//             output.emplace(input.top());
//             input.pop();
//         }
//         int x = output.top();
//         return x;
//     }
    
//     bool empty() {
//         return input.empty() and output.empty();
//     }
// };

/**

O(n) time & space

You have 2 stacks: s1 and s2
push - O(n)
1. first transfer everything from s1 to s2
2. push into s1
3. transfer back everything from s2 to s1
pop & top - return top of s1 - O(1)
empty - check if s1 is empty - O(1)

class MyQueue {
private:
    stack<int> s1, s2;
public:
    MyQueue() {}
    
    void push(int x) {
        while(!s1.empty()) {
            s2.emplace(s1.top());
            s1.pop();
        }
        s1.emplace(x);
        while(!s2.empty()) {
            s1.emplace(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int top = s1.top();
        s1.pop();
        return top;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};


*/
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */