class Solution {
private:
    vector<vector<int>> rotated(vector<vector<int>> &matrix) {
        int n = size(matrix);
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < n; ++i)
            for(int j = i; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
        return matrix;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> temp = mat;
        for(int i = 0; i < 4; ++i) {
            temp = rotated(temp);
            if(target == temp) return true;
        }
        return false;
    }
};