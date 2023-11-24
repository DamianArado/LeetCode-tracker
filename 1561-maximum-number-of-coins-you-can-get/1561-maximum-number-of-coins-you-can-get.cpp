class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = size(piles), pickTimes = n / 3, coins = 0, idx = n - 2;
        sort(begin(piles), end(piles));
        for (int i = 0; i < pickTimes; ++i) {
            coins += piles[idx];
            idx -= 2;
        }
        return coins;
    }
};