/*

Solution - I (Recursive DFS - Preorder)

We can intuitively see that a DFS solution will fit well here since we traverse from root to leaf in a DFS traversal and thus we can use it to form number represented by each root-to-leaf path. In DFS traversal -

We start at the root with current number cur = 0.
Every time, the current node's digit will be appended to cur from root to leaf and we recurse for left and right child.
If we reach a leaf node (a node not having any left or right child), we have formed the complete root-to-leaf number. We will then add this number cur to the overall sum.

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    // preorder dfs traversal
    int dfs(TreeNode* root, int cur) {
        if(!root) return 0;
        cur = cur * 10 + root -> val;                 // append current node's digit
        if(!root -> left && !root -> right)           // leaf node - return current number to be added to total sum
            return cur;
        return dfs(root -> left, cur) + dfs(root -> right, cur);   // recurse for child if current node is not leaf
    }  
};

TC - O(n) & SC - O(h)

--------------------------------------------------------------------------------------------------------------------------

Solution - II (Iterative DFS - preorder)

The same as above but converted to iterative solution using an explicit stack. The working and complexities should be about the same for both the solutions. But, an interviewer may ocassionally ask to implement iterative version, so it's good to know this as well.

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;      // {node, cur}
        s.push({root, 0});
        int sum = 0;
        while(!s.empty()) {
            auto [root, cur] = s.top(); s.pop();
            cur = cur * 10 + root -> val;
            if(!root -> left && !root -> right) sum += cur;  // reached leaf node
            if(root -> right) s.push({root -> right, cur});
            if(root -> left) s.push({root -> left, cur});
        }
        return sum;
    }
};

Solution - III (BFS)

The problem doesn't intuitively fall under BFS but it can be solved using this traversal approach as well.

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(q.size()) {
            auto [n, cur] = q.front(); q.pop();
            cur = cur * 10 + n -> val;
            if(n -> left) q.push({n -> left, cur});      
            if(n -> right) q.push({n -> right, cur});
            if(!n -> left && !n -> right) sum += cur;   // add to total sum if we are at leaf node
        }
        return sum;
    }
};

TC - O(n), SC - O(n) as atmost (n+1)/2 elements will be stored in queue in case of complete binary tree.

Solution - IV (Morris Traversal - Preorder)

This solution involves using the morris traversal technique to solve the problem. The advantage of this traversal is that we can traverse the tree in O(1) space complexity. The basic idea is to link predecessors to root nodes so we can trace it back once we have traversed a side without need of using a stack.

TC - O(n) SC - O(1)

 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0, cur = 0, depth = 0;
        while(root) {
            if(root -> left) {
                auto pre = root -> left;
                depth = 1;
                while(pre -> right && pre -> right != root) 
                    pre = pre -> right, depth++;
                if(!pre -> right) {
                    pre -> right = root;
                    cur = cur * 10 + root -> val;
                    root = root -> left;
                } else {
                    pre -> right = nullptr;
                    if(!pre -> left) sum += cur;
                    cur /= pow(10, depth);
                    root = root -> right;
                }
            } else {
                cur = cur * 10 + root -> val;
                if(!root -> right) sum += cur;
                root = root -> right;
            }
        }
        return sum;
    }
};