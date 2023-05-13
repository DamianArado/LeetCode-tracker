class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int rows = size(nums), cols = size(nums[0]);
        int score = 0;
        for(int i = 0; i < rows; ++i) {
            sort(nums[i].begin(), nums[i].end());
        }
        for(int j = 0; j < cols; ++j) {
            int maxElem = -1;
            for(int i = 0; i < rows; ++i)
                maxElem = max(maxElem, nums[i][j]);
            score += maxElem;
        }
        return score;
    }
};