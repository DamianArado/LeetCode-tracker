class Solution {
public:
    int longestCycle(vector<int> &edges) {
        // support variables
        int res = -1;
        for (int i = 0, len = edges.size(), j, k = -2000000000, curr, prev; i < len; i++) {
            prev = i, curr = edges[i];
            // n is either a dead end or already visited
            if (curr < 0) continue;
            j = k;
            while (curr >= 0) {
                // marking the source cell as visited
                edges[prev] = j--;
                // updating curr and prev
                prev = curr;
                curr = edges[curr];
            }
            // updating res if we did not reach a dead-end
            if (curr != -1) res = max(res, curr - j);
            k += 10000;
        }
        return res;
    }
};