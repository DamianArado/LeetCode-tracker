class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> lis, ans = obstacles;
        for (int i = 0; i < size(obstacles); ++i) {
            int x = obstacles[i];
            if (lis.empty() or lis[size(lis) - 1] <= x) { // Append to LIS if new element is >= last element in LIS
                lis.emplace_back(x);
                ans[i] = size(lis);
            } else {
                int idx = upper_bound(begin(lis), end(lis), x) - begin(lis); // Find the index of the smallest number > x
                lis[idx] = x; // Replace that number with x
                ans[i] = idx + 1;
            }
        }
        return ans;
    }
};