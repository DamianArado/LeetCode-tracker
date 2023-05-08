class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        if(n1 != n2) return false;
        vector<int> freq(26);
        for(const char &c : s) freq[c - 'a']++;
        for(const char &c : t) freq[c - 'a']--;
        for(const int &i : freq)
            if(i != 0) return false;
        return true;
    }
};