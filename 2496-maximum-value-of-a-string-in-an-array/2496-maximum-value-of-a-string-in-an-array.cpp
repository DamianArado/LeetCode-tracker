class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maxVal = 0;
        for(string &str : strs) {
            bool isChar = false;
            for(char &c : str) {
                if(c >= 'a' and c <= 'z') {
                    isChar = true;
                    int size = str.size();
                    maxVal = max(maxVal, size);
                    continue;
                }
            }
            if(!isChar) {
                int val = stoi(str);
                maxVal = max(maxVal, val);
            }
        }
        return maxVal;
    }
};