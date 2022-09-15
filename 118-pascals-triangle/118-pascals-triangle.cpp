class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        // you will need to go "numRows" level deep
        for(int level = 0; level < numRows; ++level) {
            // at each level, we can have only (level + 1) elements
            ans[level].resize(level + 1);
            // the first and last element is 1
            ans[level][0] = ans[level][level] = 1;
            // processing the elements except the first and last ones
            for(int i = 1; i < level; ++i)
                ans[level][i] = ans[level - 1][i - 1] + ans[level - 1][i];
        }
        return ans;
    }
};