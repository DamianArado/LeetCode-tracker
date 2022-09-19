class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long minMoney = 0; int minTransTillNow = 0;
        for(auto &transaction : transactions) {
            minTransTillNow = max(minTransTillNow, min(transaction[0], transaction[1]));
            minMoney += max(transaction[0] - transaction[1], 0);
        }
        return minTransTillNow + minMoney;
    }
};