class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        // (0, 0) -> (0, 0)
        // (1, 0) -> (1, 1)
        // (0, 1) -> (1, 1)
        // (1, 1) -> (1, 0)
        // if it has a 1 it can flip it's value as 0 cannot change
        return (s.find('1') != string::npos) == (t.find('1') != string::npos);
    }
};