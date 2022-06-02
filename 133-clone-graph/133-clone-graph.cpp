/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// TC - O(|V| + |E|), SC - O(|V|)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        // mapping of Node
        unordered_map<Node*,Node*> vertexMap;
        queue<Node*> q;
        q.emplace(node);
        vertexMap.emplace(node, new Node({node->val}));
        
        // bfs
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            for(auto e : v->neighbors) {
                // copy vertex
                if(vertexMap.find(e) == vertexMap.end()) {
                    vertexMap.emplace(e, new Node({e->val}));
                    q.emplace(e);
                }
                // copy edge v -> e
                vertexMap[v]->neighbors.emplace_back(vertexMap[e]);
            }
        }
        return vertexMap[node];
    }
};