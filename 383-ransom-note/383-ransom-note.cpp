class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = ransomNote.size(), n = magazine.size();
        if(m > n) return false;
        
        vector<int> freqRN(26, 0), freqM(26, 0);
        for(char &c : magazine) freqM[c - 'a']++;
        for(char &c : ransomNote) freqRN[c - 'a']++;
        
        for(char &c : magazine) freqRN[c - 'a']--;
        for(char &c : ransomNote) 
            if(freqRN[c - 'a'] > 0) 
                return false;
        return true;
    }
};