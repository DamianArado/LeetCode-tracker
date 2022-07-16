class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0, n = heights.size();
        for(int i = 0; i <= n; ++i) {
            while(!st.empty() and (i == n or heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                maxArea = max(maxArea, width * height);
            }
            st.push(i);
        }
        return maxArea;
    }
public:
    // TC: O(row*col) SC: O(col)
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0, row = matrix.size(), col = matrix[0].size();
        vector<int> height(col, 0);
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(matrix[i][j] == '1') 
                    height[j]++;
                else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};