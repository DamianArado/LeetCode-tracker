class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(const char &c : s) {
            if(c == '(' or c == '{' or c == '[') st.emplace(c);
            else {
                if(st.empty()) return false;
                const char &current = st.top();
                st.pop();
                if((current == '(' and c != ')') or (current == '{' and c != '}') 
                   or (current == '[' and c != ']')) return false;
            }
        }
        return st.empty();
    }
};