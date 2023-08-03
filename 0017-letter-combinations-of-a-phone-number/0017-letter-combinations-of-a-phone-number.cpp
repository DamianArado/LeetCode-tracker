class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0)
            return result;
        result.push_back("");
        string charMap[10] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for (int i = 0; i < digits.size(); ++i) {
            string chars = charMap[digits[i] - '0'];
            vector<string> temp;
            for (int c = 0; c < chars.size(); ++c)
                for (int j = 0; j < result.size(); ++j)
                    temp.push_back(result[j] + chars[c]);
            result = temp;
        }
        return result;
    }
};