/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "x";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(queue<string> &q) {
        if(q.empty()) return NULL;
        string current = q.front(); q.pop();
        if(current == "x") return NULL;
        TreeNode *node = new TreeNode(stoi(current));
        node->left = deserialize(q);
        node->right = deserialize(q);
        return node;
    }
    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp;
        for(char &c : data) {
            if(c == ',') {
                q.emplace(temp);
                temp = "";
            } else temp += c;
        }
        return deserialize(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;