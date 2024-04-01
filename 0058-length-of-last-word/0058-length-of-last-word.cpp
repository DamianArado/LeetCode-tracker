class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastWordLen = 0, currentWordLen = 0;
        for (const char &c : s) 
            if (c == ' ')
                currentWordLen = 0;
            else 
                lastWordLen = ++currentWordLen;
        return lastWordLen;
    }
};