// class Solution {
// private:
//     // recurrence
//     long long mod = 1e9 + 7;
//     int f(int idx, bool canPlace) {
//         if(idx == 1) return 1;
//         if(!canPlace) return f(idx - 1, !canPlace);
//         return (f(idx - 1, !canPlace) + f(idx - 1, canPlace)) % (mod);
//     }
// public:
//     int countHousePlacements(int n) {
//         long long ways = (f(n, 0) + f(n, 1)) % (mod);
//         return (ways * ways) % (mod);
//     }
// };

/***

Thinking similar to Fibonacci sequence
f(i): no. of ways to place i houses in n plots such that no 2 houses are adjacent
f(i - 1): if we don't put house in the current plot
f(i - 2): if we put house in the current plot
Hence, f(i) = f(i - 1) + f(i - 2)

*/

class Solution {
public:
    int countHousePlacements(int n) {
        if(n == 1) return 4;
        if(n == 2) return 9;
        long long pprev = 2, prev = 3, mod = 1e9 + 7;
        for(int i = 3; i <= n; ++i) {
            long long current = (prev + pprev) % (mod);
            pprev = prev, prev = current;
        }
        return (prev * prev) % (mod);
    }
};