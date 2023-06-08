// class Solution {
// public:
//     // brute force
//     int countNegatives(vector<vector<int>>& grid) {
//         int count = 0;
//         for (const vector<int> &row : grid) {
//             for (const int &val : row) 
//                 if (val < 0) ++count;
//         }
//         return count;
//     }
// };

class Solution {
private:
    int binarySearch(const vector<int> &row, int &n) {
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (row[mid] < 0) end = mid - 1;
            else start = mid + 1;
        }
        return end;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0, n = size(grid[0]);
        for (const vector<int> &row : grid) {
            // apply binary search here and find the first element which is -ve
            int negatives = binarySearch(row, n);
            count += (n - 1 - negatives);
        }
        return count;
    }
};