class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        TrieNode* root = new TrieNode();
        for (const string &word : dictionary) {
            insert(root, word);
        }
        int n = s.length();
        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + 1;
            TrieNode* node = root;
            for (int j = i; j < n; j++) {
                int c = s[j] - 'a';
                if (node->children[c] == nullptr) 
                    break;
                node = node->children[c];
                if (node->isWord) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }
        return dp[0];
    }

private:
    void insert(TrieNode* root, const string &word) {
        TrieNode* node = root;
        for (const char &c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new TrieNode();
            }
            node = node->children[i];
        }
        node->isWord = true;
    }
};