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
        // base case
        if(node == NULL) return NULL;
        // we need 2 data structures to perform BFS: queue and a map
        queue<Node*> q;
        unordered_map<Node*, Node*> vertexMap;
        // to perform BFS
        q.emplace(node);
        // to store copy nodes and create edges
        vertexMap.emplace(node, new Node(node->val));
        
        while(!q.empty()) {
            Node *current = q.front();
            q.pop();
            for(const auto adjNode : current->neighbors) {
                if(!vertexMap.count(adjNode)) {
                    // if we have not created edges for this node yet
                    vertexMap.emplace(adjNode, new Node(adjNode->val));
                    q.emplace(adjNode);
                }
                // create the undirected connections
                vertexMap[current]->neighbors.emplace_back(vertexMap[adjNode]);
            }
        }
        return vertexMap[node];
    }
};