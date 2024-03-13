// class Solution {
// public:
//     int pivotInteger(int n) {
//         for(int i = 1; i <= n; ++i) {
//             int lSum = 0, rSum = 0;
//             int j = 1, k = n;
//             while(j <= i) { lSum += j; ++j; }
//             while(k >= i) { rSum += k; --k; }
//             if(lSum == rSum) return i;
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//     int pivotInteger(int n) {
//         int sum = n * (n + 1) / 2, x = sqrt(sum);
//         return x * x == sum ? x : -1;
//     }
// };

class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2;
        double square = sqrt(sum);
        if (ceil(square) == square)
            return int(square);
        return -1;
    }
};