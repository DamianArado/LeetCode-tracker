class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = size(matrix);
        // swap alternating row elements
        reverse(begin(matrix), end(matrix));
        // take transpose
        for(int i = 0; i < n; ++i)
            for(int j = i; j < n; ++j) 
                if(i != j)
                    swap(matrix[i][j], matrix[j][i]);
    }
};