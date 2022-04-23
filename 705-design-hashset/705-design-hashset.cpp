/* 

Smart way but may not impress interviewer -

class MyHashSet {
    vector<bool> ans;
public:
    MyHashSet() {
        ans.resize(1e6 + 1, false);
    }
    
    void add(int key) {
        ans[key] = true;
    }
    
    void remove(int key) {
        ans[key] = false;
    }
    
    bool contains(int key) {
        return ans[key] == true;
    }
};

*/

// TODO : write analysis
class MyHashSet {
    struct TreeNode {
        int digit;
        bool exists;
        vector<TreeNode*> children;
        TreeNode(int digit) {
            this->exists = false;
            this->digit = digit;
        }
    };
    
    TreeNode* root;
    
public:
    MyHashSet() {
        root = new TreeNode(0);
    }
    
    void add(int key) {
        if(key == 0) {
            root->exists = true;
            return;
        }
        TreeNode* current = root;
        while(key) {
            bool found = false;
            for(auto it : current->children) {
                if(it->digit == key % 10) {
                    found = true;
                    current = it;
                    break;
                }
            }
            if(!found) {
                current->children.emplace_back(new TreeNode(key % 10));
                current = current->children.back();
            }
            key /= 10;
        }
        current->exists = true;
    }
    
    void remove(int key) {
        if(key == 0) {
            root->exists = false;
            return;
        }
        TreeNode* current = root;
        while(key) {
            bool found = false;
            for(auto it : current->children) {
                if(it->digit == key % 10) {
                    found = true;
                    current = it;
                    break;
                }
            }
            if(!found) return;
            key /= 10;
        }
        current->exists = false;
    }
    
    bool contains(int key) {
        if(key == 0) return root->exists;
        TreeNode* current = root;
        while(key) {
            bool found = false;
            for(auto it : current->children) {
                if(it->digit == key % 10) {
                    found = true;
                    current = it;
                    break;
                }
            }
            if(!found) return false;
            key /= 10;
        }
        return current->exists;
    }
};