class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), minOps = 1e9, flips = 0, count = 0, i = 0;
        for(int j = 0; j < n; ++j) {
            if(count == k) {
                minOps = min(minOps, flips);
                if(blocks[i] == 'W') {
                    flips -= 1;
                    count -= 1;
                } else count -= 1;
                i += 1;
            } 
            if(blocks[j] == 'W') {
                flips += 1;
                count += 1;
            } else if(blocks[j] == 'B') {
                count += 1;
            }
            if(count == k) minOps = min(minOps, flips);
        }
        return minOps;
    }
};