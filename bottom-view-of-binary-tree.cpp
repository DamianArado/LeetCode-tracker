vector<int> bottomView(Node* root) {
    vector<int> ans;
    if(!root) return ans;
    map<int, int> omp; // map made of [vLevel, node->val]
    queue<pair<Node*, int>> q; // queue made of [node, vLevel]
    q.push({root, 0});
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int vLevel = it.second;
        omp[node] = vLevel;
        if(node->left) q.push({node->left, vLevel - 1});
        if(node->right) q.push({node->right, vLevel + 1});
    }
    for(auto it : omp) ans.emplace_back(it.second):
    return ans;
}
