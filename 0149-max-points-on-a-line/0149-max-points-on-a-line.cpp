class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // find a slope having max number of points
        int ans = 1;
        sort(begin(points), end(points), [&] (auto x, auto y) { 
            if(x[0] == y[0]) return x[1] < y[1];
            return x[0] < y[0];
        });
        for(int i = 0; i < size(points); ++i) {
            unordered_map<double, int> m;
            for(int j = i + 1; j < size(points); ++j) {
                double x = ((double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]));
                double theta = atan(x);
                m[theta]++;
                ans = max(ans, m[theta] + 1);
            }
        }
        return ans;
    }
};