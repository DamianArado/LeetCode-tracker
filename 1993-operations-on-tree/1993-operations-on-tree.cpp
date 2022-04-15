class LockingTree {
public:
    struct Node {
        vector<Node*> ch;
        int lock = -1;
    };
    
    vector<Node> tree;
    vector<int> parent;
    
    LockingTree(vector<int>& parent) : parent(parent) {
        tree = vector<Node>(parent.size());
        for (int i = 1; i < parent.size(); ++i)
            tree[parent[i]].ch.push_back(&tree[i]);
    }
    
    bool updateLock(Node &node, int oldVal, int newVal) {
        if (node.lock != oldVal)
            return false;
        node.lock = newVal;
        return true;
    }
    
    bool lock(int num, int user) { return updateLock(tree[num], -1, user); }
    
    bool unlock(int num, int user) { return updateLock(tree[num], user, -1); }
    
    bool upgrade(int num, int user) {
        for (int i = num; i != -1; i = parent[i])
            if (tree[i].lock != -1)
                return false;
        if (!anyLocked(&tree[num]))
            return false;
        unlock(&tree[num]);
        return updateLock(tree[num], -1, user);
    }
    
    bool anyLocked(const Node *n) {
        return n->lock != -1 || any_of(begin(n->ch), end(n->ch), [&](const auto *n) { 
            return anyLocked(n); 
        });
    }
    
    void unlock(Node *n) {
        n->lock = -1;
        for(auto ch : n->ch)
            unlock(ch);
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */