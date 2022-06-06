class Solution {
private:
    string decodeString(const string &s, int &index) {
        string result;
        while(index < s.size() && s[index] != ']') {
            if(!isdigit(s[index])) {
                result += s[index++];
            } else {
                int n = 0; 
                // number of times chars will be repeated
                while(index < s.size() && isdigit(s[index]))
                    n = 10 * n + s[index++] - '0';
                index++;  // '['
                string chars = decodeString(s, index);
                index++;  // ']'
                while(n--)
                    result += chars;
            }
        }
        return result;
    }
public:
    string decodeString(string s) {
        int index = 0;
        return decodeString(s, index);
    }
};