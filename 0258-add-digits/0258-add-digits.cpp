class Solution {
public:
    int addDigits(int num) {
        string n = to_string(num);
        while(size(n) != 1) {
            int sum = 0;
            for(const char &c : n) sum += (c - '0');
            n = to_string(sum);
        }
        return stoi(n);
    }
};