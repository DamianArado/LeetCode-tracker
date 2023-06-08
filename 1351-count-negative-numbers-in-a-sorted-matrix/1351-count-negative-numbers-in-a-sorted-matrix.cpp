class Solution {
public:
    // brute force
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (const vector<int> &row : grid) {
            for (const int &val : row) 
                if (val < 0) ++count;
        }
        return count;
    }
};