///
//
// Till index idx, can we break the string into a sequence of words given in the word dictionary?
//
///
// class Solution {
// private:
//     bool f(int idx, string &s, unordered_set<string> &st) {
//         if(idx == size(s)) return true;
//         string temp;
//         for(int i = idx; i < size(s); ++i) {
//             temp += s[i];
//             if(st.count(temp) and f(i + 1, s, st)) 
//                 return true; 
//         }
//         return false;
//     }
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> st;
//         for(string &words : wordDict) st.insert(words);
//         return f(0, s, st);
//     }
// };
    
// Let's optimize and store the answer for each index inside a dp array
class Solution {
private:
    int f(int idx, string &s, unordered_set<string> &st, vector<int> &dp) {
        if(idx == size(s)) return dp[idx] = true;
        if(dp[idx] != -1) return dp[idx];
        string temp;
        for(int i = idx; i < size(s); ++i) {
            temp += s[i];
            if(st.count(temp) and f(i + 1, s, st, dp)) 
                return dp[idx] = true; 
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n + 1, -1);
        unordered_set<string> st;
        for(string &words : wordDict) st.insert(words);
        return f(0, s, st, dp);
    }
};