/*

Problem link: https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?leftPanelTab=0

1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.

2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.

3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.

4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

5) erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.

TC : O(length of word)
SC: O(number of trie nodes)

*/

struct Node {
	Node* linkNext[26];  // total links required
	int countEndsWith = 0; // number of words ending with
	int countPrefix = 0;  // number of words starting with
	
	bool containsKey(char ch) {
		return (linkNext[ch - 'a'] != NULL);  // if we have a char at that link
	}
	
	void put(char ch, Node* newNode) {
		linkNext[ch - 'a'] = newNode;  // linkNext->new node = newNode
	}
	
	void increasePrefix() { countPrefix++; }  // for app, apple, at last p, prefix++
	
	void increaseEnd() { countEndsWith++; }  // for app and app, at last node, endsWith = 2
	
	Node* getNext(char ch) {
		return linkNext[ch - 'a'];  // get the next link node for this char
	}
	
	int getEnd() { return countEndsWith; }  // return no. of elements ending with character
	
	int getPrefix() { return countPrefix; }  // return no. of elements starting with character
	
	void reducePrefix() { countPrefix--; }  // reduce the no. of elements starting with char (for deletion)
	
	void reduceEndsWith() { countEndsWith--; } // reduce the no. of elements ending with char (for deletion)
};

class Trie {
	
	Node* root;

    public:

    Trie() {
		// every time we need a new node as the Trie node
        root = new Node();
    }

    void insert(string &word){
        Node* current = root;
		// Iterate over the characters
		for(int i = 0; i < word.size(); i++) {
			// If it doesn't exist add it to the link
			if(!current->containsKey(word[i])) 
				current->put(word[i], new Node());
			// move onto the next node
			current = current->getNext(word[i]);
			// and increase prefix as we added a char in the node before this
			current->increasePrefix();
		}
		// as we added a word so we increase if we add it twice or more
		current->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* current = root;
		for(int i = 0; i < word.size(); i++) {
			if(current->containsKey(word[i])) {
				current = current->getNext(word[i]);  // keep matching
			} else {
				return 0; // no such word
			}
		}
		// all characters matched, return endsWith count
		return current->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* current = root;
		for(int i = 0; i < word.size(); i++) {
			if(current->containsKey(word[i])) {
				current = current->getNext(word[i]);  // keep matching
			} else {
				return 0;  // no such word exists
			}
		}
		// all characters matched, return prefix count
		return current->getPrefix();
    }

    void erase(string &word){
        Node* current = root;
		for(int i = 0; i < word.size(); i++) {
			if(current->containsKey(word[i])) {
				current = current->getNext(word[i]); // keep matching
				current->reducePrefix(); // keep decreasing the prefix
			} else {
				return; // no such word exists
			}
		}
		// since we are deleting the word, we reduce the ends with count
		current->reduceEndsWith();
    }
};
