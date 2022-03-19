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
    // TC -> O(n) SC -> O(n)

    // Encodes a tree to a single string.
    // Inorder: [4,2,1,3]  --> serialization --> String: [1,2,3,4,#,#,#]
    string serialize(TreeNode* root) {
        if(!root) return "";
        string result = "";
        queue<TreeNode*> q; // for level-order traversal
        q.emplace(root);
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if(!current) result.append("#,"); // if its null
            else result.append(to_string(current->val) + ','); // else add number to string
            if(current) {
                q.emplace(current->left);
                q.emplace(current->right);
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            getline(s, str, ','); // check for left child
            if(str == "#") current->left = NULL;
            else {
                TreeNode* leftChild = new TreeNode(stoi(str));
                current->left = leftChild;
                q.emplace(leftChild);
            }
            getline(s, str, ','); // check for right child
            if(str == "#") current->right = NULL;
            else {
                TreeNode* rightChild = new TreeNode(stoi(str));
                current->right = rightChild;
                q.emplace(rightChild);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));