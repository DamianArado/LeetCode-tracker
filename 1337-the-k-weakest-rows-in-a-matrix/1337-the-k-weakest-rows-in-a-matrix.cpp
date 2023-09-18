typedef pair<int, int> pii;
class Solution {
private:
    int findSoldierCount(const vector<int> &row) {
        int left = 0, right = size(row) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == 1)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return left;
    }
public:
    // O(nlogm) + O(nlogn); 
    // m = no. of elements in row, n = no. of elements in column
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pii, vector<pii>, greater<>> minHeap;
        int idx = 0, n = size(mat), hSize = n;
        vector<int> ans;
        for (const auto &row : mat) {
            int soldiers = findSoldierCount(row); // log m
            minHeap.emplace(soldiers, idx++);  // log n
        }
        while (hSize-- > n - k) {
            ans.emplace_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};