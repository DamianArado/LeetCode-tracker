class Solution {
    public int countHousePlacements(int n) {
        if(n == 1) return 4;
        if(n == 2) return 9;
        long pprev = 2, prev = 3, mod = 1000000007;
        for(int i = 3; i <= n; ++i) {
            long current = (prev + pprev) % (mod);
            pprev = prev;
            prev = current;
        }
        return (int) ((prev * prev) % (mod));
    }
}