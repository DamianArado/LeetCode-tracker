/*

Problem link: https://www.codingninjas.com/codestudio/problems/complete-string_2687860
(A string is called a complete string if every prefix of this string is also present in the array ‘A’. 
Ninja is challenged to find the longest complete string in the array ‘A’.
If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None".)

In this approach, we'll do the following steps -

1. Try to insert all the strings into the trie data structure. After inserting all the 
characters of a particular word, mark the next trie node's isEndOfString to true. [next trie node = reference trie node]

2. After inserting all, we will start to check which string is our longest complete string. 
If the corresponding trie node to our last char in word = true, its a possible longest complete string. 
Its a complete string if the array has all the prefixes and we check that by checking the reference node
of the trie node. 

TC - O(number of words * max length of word)
SC - O(26*26*26...)

*/

struct Node {
	Node* linkNext[26];
	bool isEndOfString = false;
	
	bool containsKey(char ch) {
		return (linkNext[ch - 'a'] != nullptr);
	}
	
	Node* getNext(char ch) {
		return (linkNext[ch - 'a']);
	}
	
	void put(char ch, Node* newNode) {
		linkNext[ch - 'a'] = newNode;
	}
	
	void setEnd() { isEndOfString = true; }
	
	bool isEnd() { return isEndOfString; }
};

class Trie {
	private: Node* root;
	
	public:
		Trie() {
			root = new Node();
		}
		
		// insert the word in trie
		void insert(string word) {
			Node* current = root;
			for(int i = 0; i < word.size(); i++) {
				if(!current->containsKey(word[i])) {
					current->put(word[i], new Node());
				}
				current = current->getNext(word[i]);
			}
			current->setEnd();
		}
		// checking to see that all prefixes exist in trie ds
		bool checkIfAllPrefixesExist(string word) {
			Node* current = root;
			bool flag = true;
			for(int i = 0; i < word.size(); i++) {
				if(current->containsKey(word[i])) {
					current = current->getNext(word[i]);
					flag = flag & current->isEnd();
				} else 
					return false;
			}
			return flag;
		}
};

string completeString(int n, vector<string> &a) {
    if(n == 1) return a[0];
	Trie* obj = new Trie();
	for(auto strings : a) obj->insert(strings);
	string completeStr = "";
	for(auto strings : a) {
		if(obj->checkIfAllPrefixesExist(strings)) {
			// longer
			if(strings.size() > completeStr.size()) {
				completeStr = strings;
			// same size but lexicographically smaller
			} else if(strings.size() == completeStr.size() && strings < completeStr) {
				completeStr = strings;
			}
		}
	}
	if(completeStr == "") return "None";
	return completeStr;
}
