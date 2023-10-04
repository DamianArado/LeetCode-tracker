class Solution {
public:
    string smallestSubsequence(string s) {
        int n = size(s);
        if (n == 1) 
            return s;
        vector<int> lastIdx(26);
        vector<bool> seen(26, false);
        stack<int> st;
        for (int i = 0; i < n; ++i)
            lastIdx[s[i] - 'a'] = i;
        for (int i = 0; i < n; ++i) {
            int current = s[i] - 'a';
            // lexicographical ordering
            if (seen[current]) continue;
            // current < s.top() and i < lastIdx[s.top()] -> a bigger one already exists on the right side of string so discard this one
            while (!st.empty() and current < st.top() and i < lastIdx[st.top()]) {
                seen[st.top()] = false;
                st.pop();
            }
            st.emplace(current);
            seen[current] = true;
        }
        string ans = "";
        while (!st.empty()) {
            ans += 'a' + st.top();
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};