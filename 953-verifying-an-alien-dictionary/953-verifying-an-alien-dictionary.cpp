/*
    Explanation
    Build a transform mapping from order,
    Find all alien words with letters in normal order.

    For example, if we have order = "xyz..."
    We can map the word "xyz" to "abc" or "123"

    Then we check if all words are in sorted order.

    Complexity: Time O(NS), Space O(1)
*/
class Solution {
public:
    bool isAlienSorted(vector<string> words, string order) {
        int mapping[26];
        for (int i = 0; i < 26; ++i)
            mapping[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w) c = mapping[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
};