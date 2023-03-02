class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0, right = 0;
        while(right < size(chars)) {
            char current = chars[right];
            int count = 0;
            while(right < size(chars) and chars[right] == current) {
                ++count;
                ++right;
            }
            chars[left++] = current;
            if(count != 1) {
                string counts = to_string(count);
                for(char &c : counts) chars[left++] = c;
            }
        }
        return left;
    }
};