/*

Problem link: https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292
(Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) 
of the given string. You should implement the program using a trie.)

Using the tries approach, we are concerned about whether the word exists or not. So, we'll
not use the boolean property here.

We will add characters only if they didn't exist and we'll increase the answer.

TC - O(n^2)
SC - O(26*26*26*..) although highly unlikely that this may happen

*/

struct Node {
	Node* linkNext[26]; 
	
	bool containsKey(char ch) {
		return (linkNext[ch - 'a'] != nullptr);
	}
	
	void put(char ch, Node* newNode) {
		linkNext[ch - 'a'] = newNode;
	}
	
	Node* getNext(char ch) {
		return (linkNext[ch - 'a']);
	}
};

class Trie {
	private: Node* root;
	public:
		Trie() {
			root = new Node();
		}
	
		int insert(string &s) {
			int ans = 1;
			for(int i = 0; i < s.size(); i++) {
				Node* current = root;
				for(int j = i; j < s.size(); j++) {
					if(!current->containsKey(s[j])) {
						current->put(s[j], new Node());
						ans++;
					}
					current = current->getNext(s[j]);
				}
			}
			return ans;
		}
};

int countDistinctSubstrings(string &s) {
	if(s.size() == 1) return 2;
	Trie* obj = new Trie();
	return obj->insert(s);
}
