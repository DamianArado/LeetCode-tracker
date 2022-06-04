class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return res;
        string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i = 0; i < digits.size(); i++)
        {
            vector<string> tempres;
            string chars = charmap[digits[i] - '0'];
            for (int c = 0; c < chars.size();c++)
                for (int j = 0; j < res.size();j++)
                    tempres.push_back(res[j]+chars[c]);
            res = tempres;
        }
        return res;
    }
};