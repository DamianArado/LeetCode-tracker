class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev_row;
        prev_row.emplace_back(1);
        for (int level = 1; level <= rowIndex; ++level) {
            vector<int> curr_row(level + 1);
            curr_row[0] = curr_row[level] = 1;
            for (int i = 1; i < level; ++i)
                curr_row[i] = prev_row[i - 1] + prev_row[i];
            prev_row = curr_row;
        }
        return prev_row;
    }
};