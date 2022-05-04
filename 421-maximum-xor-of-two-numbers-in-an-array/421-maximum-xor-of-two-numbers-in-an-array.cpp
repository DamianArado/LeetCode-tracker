/*

Time complexity = O(32*N) [for inserting all the elements of nums into the trie ; 32-bit and for finding the max XOR for every element of nums]

Space complexity = O(32*N) since we are inserting all the elements of nums into the trie where every element is of size 32-bit but the actual 
sc will be less than O(32*N) because they might have overlapped.

*/

struct Node {
    Node* linkNext[2];
    
    bool containsKey(int bit) {
        return (linkNext[bit] != NULL);
    }
    
    void put(int bit, Node* newNode) {
        linkNext[bit] = newNode;
    }
    
    Node* getNext(int bit) {
        return linkNext[bit];
    }

};

class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(int number) {
       Node* current = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (number >> i) & 1;
            if(!current->containsKey(bit)) {
                current->put(bit, new Node());
            }
            current = current->getNext(bit);
        }
    }
    
    int findMax(int number) {
         Node* current = root;
        int maxXOR = 0;
        // inserting from left to right
        for(int i = 31; i >= 0; i--) {
            // check if the bit is 1 or 0
            int bit = (number >> i) & 1;
            // check if we have the opposite bit at the current node in trie
            if(current ->containsKey(1 - bit)) {
                // making sure we get 1 at this bit
                maxXOR = maxXOR | (1 << i);
                // move to the reference node of this choice
                current = current->getNext(1 - bit);
            }else {
                // if cant we take the 0 and keep moving
                current = current->getNext(bit);
            }
        }
        return maxXOR;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trieObj;
        for(auto &it : nums) {
            // first we insert all the numbers bit-by-bit into the trie
            trieObj.insert(it);
        }
        int ans = 0;
        for(auto &it : nums){
            // returns the max from this array
            ans = max(ans, trieObj.findMax(it));
        }
        return ans;
    }
};
