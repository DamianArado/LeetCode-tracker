/**

Beautiful integer: sum of digits of (n + x) <= target
where x is min possible whole no.

This algorithm finds the optimum (n + x) such that their sum <= target => (n * base) - n0
In order to find the minimum possible integer, we do => n = n / 10 + 1 with base *= 10 at each step
eliminating digits and adding one to the next from R -> L

*/
typedef long long ll;
class Solution {
private:
    ll sum(ll num) {
        ll ans = 0;
        while(num) {
            ans += num % 10;
            num = num / 10;
        }
        return ans;
    }
public:
    ll makeIntegerBeautiful(ll n, int target) {
        ll n0 = n, base = 1;
        // O(log(10)n * log(10)n) time
        while(sum(n) > target) {
            n = n / 10 + 1;
            base *= 10;
        }
        return (base * n) - n0;
    }
};