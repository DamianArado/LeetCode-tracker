class Solution {
public:
    /**
    
    Strategy - 
    1. If positive: sort in ascending order and then swap first element with the first non-zero element
    2. If negative: sort in descending order
    
    */
    long long smallestNumber(long long num) {
        string s = to_string(num);
        sort(begin(s), end(s), [&] (int x, int y) {
            return num < 0 ? x > y : x < y;
        });
        if(num > 0) swap(s[0], s[s.find_first_not_of('0')]);
        return stoll(s) * (num < 0 ? -1 : 1);
    }
};