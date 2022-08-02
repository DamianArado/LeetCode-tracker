/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> verticalOrder;
        if(!root) return verticalOrder;
        /**
        * We need 2 auxiliary data structures here: A Queue for doing the level order traversal 
        * and a Map for storing the verticalNo and levelNo for each node traversed during BFS
        
        * Significance -
        * Queue<Node, <Vertical, Level>>
        * Map<Vertical, <Level, Sorted nodes in asc order in this level>>
        
        */
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> nodes;
        
        // push the root node into the BFS queue - vertical = 0 & level = 0
        q.push({root, {0, 0}});
        
        // BFS or Level order traversal
        while(!q.empty()) {
            // Add the element into our map
            TreeNode* current = q.front().first;
            int verticalNo = q.front().second.first;
            int levelNo = q.front().second.second;
            q.pop();
            nodes[verticalNo][levelNo].insert(current->val);
            
            // Add elements in the queue
            if(current->left)
                q.push({current->left, {verticalNo - 1, levelNo + 1}});
            if(current->right)
                q.push({current->right, {verticalNo + 1, levelNo + 1}});
        }
        
        // Start adding the nodes into your answer: vertical-by-vertical
        for(auto node : nodes) {
            vector<int> vertical;
            // Add the nodes in this vertical into the vertical order traversal
            for(auto verticalNodes : node.second)
                // v v imp - VERTICAL.END() 
                vertical.insert(vertical.end(), verticalNodes.second.begin(), verticalNodes.second.end());
            verticalOrder.push_back(vertical);
        }
        
        return verticalOrder;
    }
};