class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int deletions = 0;
        int row = size(strs), col = size(strs[0]);
        for(int i = 0; i < col; ++i) {
            for(int j = 1; j < row; ++j) {
                if(strs[j - 1][i] > strs[j][i]) {
                    deletions++;
                    break;
                }
            }
        }
        return deletions;
    }
};