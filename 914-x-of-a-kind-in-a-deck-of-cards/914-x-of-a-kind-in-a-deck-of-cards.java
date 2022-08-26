class Solution {
    private int gcd(int a, int b) {
        return b > 0 ? gcd(b, a % b) : a;
    }
    public boolean hasGroupsSizeX(int[] deck) {
        int ans = 0;
        var map = new HashMap<Integer, Integer>();
        for(int card : deck) map.put(card, map.getOrDefault(card, 0) + 1);
        for(int freq : map.values()) ans = gcd(freq, ans);
        return ans > 1;
    }
}