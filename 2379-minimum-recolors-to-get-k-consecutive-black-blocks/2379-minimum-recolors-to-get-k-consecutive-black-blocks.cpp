class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), minOps = 1e9, flips = 0, count = 0, i = 0;
        for(int j = 0; j < n; ++j) {
            if(blocks[j] == 'W') {
                flips++;
                count++;
            } else if(blocks[j] == 'B') {
                count++;
            }
            if(count == k) {
                minOps = min(minOps, flips);
                if(blocks[i] == 'W') {
                    flips--;
                    count--;
                } else count--;
                i++;
            }
        }
        return minOps;
    }
};