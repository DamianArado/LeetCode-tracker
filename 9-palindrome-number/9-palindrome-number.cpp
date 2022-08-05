class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 or (x != 0 and x % 10 == 0)) return false;
        int reverse = 0;
        // reverse till the mid and compare
        while(x > reverse) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return x == reverse or x == reverse / 10;
    }
};