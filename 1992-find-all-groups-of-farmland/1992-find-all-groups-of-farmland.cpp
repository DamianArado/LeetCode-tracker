class Solution {
private:
    void findCoordinates(vector<vector<int>> &land, vector<vector<int>> &coordinates, const int &row, const int &column, const int &rows, const int &columns) {
        land[row][column] = 0;
        vector<int> coordinate = {row, column};
        coordinates.emplace_back(coordinate);
        if (row + 1 < rows and land[row + 1][column])
            findCoordinates(land, coordinates, row + 1, column, rows, columns);
        if (row - 1 >= 0 and land[row - 1][column])
            findCoordinates(land, coordinates, row - 1, column, rows, columns);
        if (column + 1 < columns and land[row][column + 1])
            findCoordinates(land, coordinates, row, column + 1, rows, columns);
        if (column - 1 >= 0 and land[row][column - 1])
            findCoordinates(land, coordinates, row, column - 1, rows, columns);
    }
    vector<int> findFarm(vector<vector<int>> &coordinates) {
        int n = size(coordinates);
        if (n == 1) {
            int e1 = coordinates[0][0], e2 = coordinates[0][1];
            return {e1, e2, e1, e2};
        }
        sort(begin(coordinates), end(coordinates), [&] (auto x, auto y) {
            return x[0] != y[0] ? x[0] < y[0] : x[1] < y[1];
        });
        int e1 = coordinates[0][0], e2 = coordinates[0][1], e3 = coordinates[n - 1][0], e4 = coordinates[n - 1][1];
        return {e1, e2, e3, e4};
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rows = size(land), columns = size(land[0]);
        vector<vector<int>> coordinates, ans;
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                if (land[row][column]) {
                    findCoordinates(land, coordinates, row, column, rows, columns);
                    ans.emplace_back(findFarm(coordinates));
                    coordinates.clear();
                }
            }
        }
        return ans;
    }
};