class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        if(s1.size() < s2.size()) return gcdOfStrings(s2, s1); 
        if(s2.empty()) return s1;  // got the required GCD
        if(s1.substr(0, s2.size()) != s2) return "";  // can't be a GCD
        return gcdOfStrings(s1.substr(s2.size()), s2);  // remove the s2.size() chars from front of s1
    }
};