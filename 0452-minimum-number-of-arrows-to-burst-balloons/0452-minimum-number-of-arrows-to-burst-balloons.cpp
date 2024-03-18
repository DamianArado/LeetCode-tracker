class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = size(points);
        if (n == 1) 
            return 1;
        sort(begin(points), end(points), [] (vector<int>& x, vector<int>& y) { 
            return x[1] < y[1]; 
        });
        int arrows = 1, arrowEnd = points[0][1];
        for (int i = 1; i < n; ++i) {
            if (arrowEnd < points[i][0]) {
                ++arrows;
                arrowEnd = points[i][1];
            }
        }
        return arrows;
    }
};