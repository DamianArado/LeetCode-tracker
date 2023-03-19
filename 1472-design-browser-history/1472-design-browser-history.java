class BrowserHistory {
    class Node {
        public String val;
        public Node prev;
        public Node next;
        Node(String val) {
            this.val = val;
            this.prev = null;
            this.next = null;
        }
    }
    private Node head;
    private Node current;

    public BrowserHistory(String homepage) {
        head = new Node(homepage);
        current = head;
    }
    
    public void visit(String url) {
        Node nextNode = new Node(url);
        current.next = nextNode;
        nextNode.prev = current;
        current = current.next;
    }
    
    public String back(int steps) {
        while(current != head && (steps-- > 0))
            current = current.prev;
        return current.val;
    }
    
    public String forward(int steps) {
        while(current.next != null && (steps-- > 0))
            current = current.next;
        return current.val;
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */