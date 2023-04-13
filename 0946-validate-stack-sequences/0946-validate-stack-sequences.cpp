class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        for (const int &val : pushed) {
            s.emplace(val);
            while (!s.empty() and s.top() == popped[i]) {
                ++i;
                s.pop();
            }
        }
        return s.empty();
    }
};