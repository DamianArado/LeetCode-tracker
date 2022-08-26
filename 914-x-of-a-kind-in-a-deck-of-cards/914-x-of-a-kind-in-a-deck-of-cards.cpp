class Solution {
private:
    int gcd(int a, int b) {
        return b > 0 ? gcd(b, a % b) : a;
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(int card: deck) mp[card]++;
        for(auto freq : mp) ans = gcd(freq.second, ans);
        return ans > 1;
    }
};