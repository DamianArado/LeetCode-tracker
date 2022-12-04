// O(mnlogmn) solution
// class Solution {
// public:
//     int findKthNumber(int m, int n, int k) {
//         vector<int> table(m*n);
//         int cnt = 0;
//         for(int i = 1; i <= m; ++i) 
//             for(int j = 1; j <= n; ++j)
//                 table[cnt++] = i*j;
//         sort(begin(table), end(table));
//         return table[k-1];
//     }
// };

class Solution {
private:
    // count the number of elements less than or equal to k inside a multiplication table
    int count(int m, int n, int k) {
        int ans = 0;
        for(int i = 1; i <= m; ++i)
            ans += min(k / i, n);
        return ans;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int start = 1, end = m * n, mid, ans;
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(count(m, n, mid) < k) start = mid + 1;
            else ans = mid, end = mid - 1;
        }
        return ans;
    }
};