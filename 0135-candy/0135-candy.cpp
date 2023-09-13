class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = size(ratings), candies = n, i = 1;
        while (i < n) {
            while (i < n and ratings[i] == ratings[i - 1])
                ++i;
            int peak = 0;
            while (i < n and ratings[i] > ratings[i - 1]) {
                ++peak; ++i;
                candies += peak;
                if (i == n) 
                    return candies;
            }
            int slope = 0;
            while (i < n and ratings[i] < ratings[i - 1]) {
                ++slope; ++i;
                candies += slope;
            }
            candies -= min(peak, slope);
        }
        return candies;
    }
};