class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Approach: max sliding window containing 2 different fruits
        int i = 0, n = size(fruits), ans = 0;
        unordered_map<int, int> mp;
        for(int j = 0; j < n; ++j) {
            ++mp[fruits[j]];
            while(size(mp) > 2) {
                if(--mp[fruits[i]] == 0) mp.erase(fruits[i]);
                ++i;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};