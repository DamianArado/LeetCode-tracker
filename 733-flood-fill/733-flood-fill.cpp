class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &ans, int oldColor, int newColor) {
        if(row == -1 or row == size(ans) or col == -1 or col == size(ans[0]) or ans[row][col] != oldColor)
            return;
        ans[row][col] = newColor;
        dfs(row - 1, col, ans, oldColor, newColor);        
        dfs(row + 1, col, ans, oldColor, newColor);
        dfs(row, col - 1, ans, oldColor, newColor);
        dfs(row, col + 1, ans, oldColor, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc], newColor = color;
        if(oldColor == newColor) return image;
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, oldColor, newColor);
        return ans;
    }
};