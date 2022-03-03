class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;
        for(int i = 0; i < candies.size(); ++i) maxCandies = max(maxCandies, candies[i]);
        vector<bool> ans;
        for(int i = 0; i < candies.size(); ++i) {
            if(candies[i] + extraCandies >= maxCandies) ans.emplace_back(true);
            else ans.emplace_back(false);
        }
        return ans;
    }
};