// Similar to Word Break I
class Solution {
private:
    bool f(int idx, string &word, unordered_set<string> &wordSet, vector<int> &dp) {
        if(wordSet.empty()) return false;
        if(idx == size(word)) return true;
        if(dp[idx] != -1) return dp[idx];
        string temp;
        for(int i = idx; i < size(word); ++i) {
            temp += word[i];
            if(wordSet.count(temp) and f(i + 1, word, wordSet, dp))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }
public:
    // TC: O(n*30^3)
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> wordSet;
        sort(begin(words), end(words), [&](auto x, auto y) { return size(x) < size(y); });
        for(string &word : words) {
            // for each word check if it is made by the concatenation of atleast 2 words
            vector<int> dp(size(word), -1);
            if(f(0, word, wordSet, dp))
                ans.emplace_back(word);
            wordSet.insert(word);
        }
        return ans;
    }
};