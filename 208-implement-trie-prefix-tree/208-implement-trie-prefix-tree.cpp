struct TrieNode {
    TrieNode* linkNext[26]; // an array of pointers that behave as reference trie nodes (links or references to the next node)
    bool isEndOfString = false; // denotes whether we reached the end of string or not
    
    // returns whether our trie contains this character as one of the reference nodes or not
    bool containsKey(char ch) {
        return (linkNext[ch - 'a'] != nullptr);
    }
    // add a trie reference node as a link if it was not already present
    void add(char ch, TrieNode* current) {
        linkNext[ch - 'a'] = current;
    }
    // get the next reference node for the current character in trie, nullptr if we are at end of string
    TrieNode* getNext(char ch) {
        return (linkNext[ch - 'a']);
    }
};

class Trie {
private:
    TrieNode* root;
public:
    // Initialize the trie object with the root node
    Trie() {
        root = new TrieNode();
    }
    // So that there are no memory leaks ;)
    ~Trie() {
        delete root;
    }
    
    // Inserts the string word into the trie data structure
    void insert(string word) {
        // we will use this node to traverse the trie data structure
        TrieNode* current = root;
        for(int i = 0; i < word.size(); i++) {
            if(!current->containsKey(word[i])) {
                current->add(word[i], new TrieNode());
            }
            current = current->getNext(word[i]);
        }
        // since we have added all the characters as links and we reach the end of string
        current->isEndOfString = true;
    }
    // Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise
    bool search(string word) {
        TrieNode* current = root;
        for(int i = 0; i < word.size(); i++) {
            if(!current->containsKey(word[i])) {
                return false;
            }
            current = current->getNext(word[i]);
        }
        // as we should be at the end of the string
        return (current->isEndOfString);
    }
    // Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for(int i = 0; i < prefix.size(); i++) {
            if(!current->containsKey(prefix[i])) {
                return false;
            }
            current = current->getNext(prefix[i]);
        }
        // as we should not be at the end of the string
        return true;
    }
};
