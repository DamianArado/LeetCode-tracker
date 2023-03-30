class Solution {
private:
    unordered_set<string> visitedFalsy;
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n != s2.size())
            return false;
        if (s1 == s2)
            return true;
        if (n == 1)
            return false;
        string key = s1 + s2;
        if (visitedFalsy.find(key) != end(visitedFalsy))
            return false;
        for (int i = 1; i < n; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))
                return true;
        }
        visitedFalsy.insert(key);
        return false;
    }
};