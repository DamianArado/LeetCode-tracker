class Solution {
    public int minimumRecolors(String blocks, int k) {
        int n = blocks.length(), minOps = Integer.MAX_VALUE, flips = 0, count = 0, i = 0;
        for(int j = 0; j < n; ++j) {
            if(blocks.charAt(j) == 'W') {
                flips++;
                count++;
            } else if(blocks.charAt(j) == 'B') {
                count++;
            }
            if(count == k) {
                minOps = Math.min(minOps, flips);
                if(blocks.charAt(i) == 'W') {
                    flips--;
                    count--;
                } else count--;
                i++;
            }
        }
        return minOps;
    }
}