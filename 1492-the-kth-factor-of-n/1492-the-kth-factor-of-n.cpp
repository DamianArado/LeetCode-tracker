class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i = 1; i <= n / 2; ++i) {
            if(n % i == 0) {
                if(k - 1 == 0) return i;
                else k = k - 1;
            }
        }
        return k == 1 ? n : -1;
    }
};