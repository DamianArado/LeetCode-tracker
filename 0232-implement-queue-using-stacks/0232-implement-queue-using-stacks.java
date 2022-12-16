class MyQueue {
    private Stack<Integer> input, output;

    public MyQueue() {
        input = new Stack<Integer>();
        output = new Stack<Integer>();
    }
    
    public void push(int x) {
        input.push(x);
    }
    
    public int pop() {
        int top;
        if(!output.isEmpty()) {
            top = output.peek();
            output.pop();
            return top;
        }
        while(!input.isEmpty()) {
            output.push(input.peek()); 
            input.pop();
        }
        top = output.peek();
        output.pop();
        return top;
    }
    
    public int peek() {
        if(!output.isEmpty()) {
            return output.peek();
        }
        while(!input.isEmpty()) {
            output.push(input.peek()); 
            input.pop();
        }
        return output.peek();
    }
    
    public boolean empty() {
        return input.isEmpty() && output.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */