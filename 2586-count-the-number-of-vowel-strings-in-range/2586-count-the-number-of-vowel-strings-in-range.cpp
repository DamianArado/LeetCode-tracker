class Solution {
private:
    bool isVowel(string &word) {
        int n = size(word);
        if((word[0] == 'a' or word[0] == 'e' or word[0] == 'i' or word[0] == 'o' or word[0] == 'u') and 
          (word[n - 1] == 'a' or word[n - 1] == 'e' or word[n - 1] == 'i' or word[n - 1] == 'o' or word[n - 1] == 'u'))
            return true;
        return false;
    }
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for(int i = left; i <= right; ++i)
            if(isVowel(words[i]))
                ++count;
        return count;
    }
};