// Time Complexity : O(N), where N is the length of output
// Space Complexity : O(L), where L is the maximum depth/levels of nested encoded string
class Solution {
    public:
        int i = 0;                                                // global variable used to track current index
        string repeat(string s, int times) {                      // repeats a string for given number of times
            for(int n = size(s); --times; s += s.substr(0, n));
            return s;
        }
        string decodeString(string& s) {
            string ans = "", n = "";
            while(i < size(s) && s[i] != ']') {                   // loop till reach end or decode current level by reaching ']'
                for(; i < size(s) && isalpha(s[i]); i++)          // 1st part
                    ans += s[i]; 
                if(i >= size(s) || s[i] == ']') continue;         // skip if next part doesn't contain number
                for(n = ""; i < size(s) && isdigit(s[i]); i++)    // 2nd part
                    n += s[i];
                i++;                                              // skip opening bracket   
                ans += repeat(decodeString(s), stoi(n));          // repeats string decoded from bracket n times
                i++;                                              // skip closing bracket    
            } 
            return ans;
        }
};