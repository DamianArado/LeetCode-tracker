class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = size(mat), sum = 0;
        for(int i = 0; i < n; ++i) 
            sum += mat[i][i];
        for(int i = 0; i < n; ++i)
            if(i != n - i - 1)
                sum += mat[i][n - i - 1];
        return sum;
    }
};