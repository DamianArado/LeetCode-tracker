class Solution {
public:
    bool isThree(int n) {
        int x = 0;
        for(int i = n; i >= 1; --i) {
            if(n % i == 0) x++;
            if(x > 3) return false;
        }
        return x == 3;
    }
};