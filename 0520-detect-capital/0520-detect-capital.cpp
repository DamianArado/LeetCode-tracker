class Solution {
public:
    bool detectCapitalUse(string s) {
        if(size(s) == 1) return true;
        int cpt = s[0] < 'a' ? 1 : 0;
        for(int i = 1; i < s[i]; ++i) 
            if(s[i] >= 'A' and s[i] <= 'Z') cpt++;
        if(cpt == 0 or (cpt == 1 and s[0] < 'a')) return true;
        return cpt == size(s);
    }
};