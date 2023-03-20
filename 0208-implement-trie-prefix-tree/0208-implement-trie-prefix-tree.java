class Trie {
    class TrieNode {
        // an array of pointers that behave as reference trie nodes (links or references to the next node)
        private TrieNode[] linkNext;
        // denotes whether we reached the end of string or not
        private boolean isEndOfString;

        public TrieNode() {
            this.linkNext = new TrieNode[26];
            this.isEndOfString = false;
        }

        // add a trie reference node as a link if it was not already present
        public void addKey(char ch, TrieNode node) {
            this.linkNext[ch - 'a'] = node;
        }

        // returns whether our trie contains this character as one of the reference nodes or not
        public boolean containsKey(char ch) {
            return this.linkNext[ch - 'a'] != null;
        }

        // get the next reference node for the current character in trie, null if we are at end of string
        public TrieNode getNext(char ch) {
            return this.linkNext[ch - 'a'];
        }

        // we reached the end of string
        public void setEnd() {
            this.isEndOfString = true;
        }

        // check whether its end of string or not
        public boolean isEnd() {
            return this.isEndOfString;
        }
    }
    private static TrieNode root;

    // Initialize the trie object with the root node
    public Trie() {
        root = new TrieNode();
    }
    
    // Inserts the string word into the trie data structure
    public void insert(String word) {
        // we will use this node to traverse the trie data structure
        TrieNode current = root;
        for(int i = 0; i < word.length(); i++) {
            if(current.containsKey(word.charAt(i)) == false) {
                current.addKey(word.charAt(i), new TrieNode());
            }
            current = current.getNext(word.charAt(i));
        }
        // since we have added all the characters as links and we reach the end of string
        current.setEnd();
    }
    
    // Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise
    public boolean search(String word) {
        TrieNode current = root;
        for(int i = 0; i < word.length(); i++) {
            if(current.containsKey(word.charAt(i)) == false) {
                return false;
            }
            current = current.getNext(word.charAt(i));
        }
        // as we should be at the end of the string
        return current.isEnd();
    }
    
    // Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise
    public boolean startsWith(String prefix) {
        TrieNode current = root;
        for(int i = 0; i < prefix.length(); i++) {
            if(current.containsKey(prefix.charAt(i)) == false) {
                return false;
            }
            current = current.getNext(prefix.charAt(i));
        }
        // as we should not be at the end of the string
        return true;
    }
}