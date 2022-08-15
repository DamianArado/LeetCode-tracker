class Solution {
    public int balancedString(String s) {
        int n = s.length(), ans = n, k = n / 4;
        var freq = new HashMap<Character, Integer>();
        freq.put('Q', 0);
        freq.put('W', 0);
        freq.put('E', 0);
        freq.put('R', 0);
        
        for(int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            freq.put(c, freq.get(c) + 1);
        }
        int i = 0;
        for(int j = 0; j < n; ++j) {
            char c = s.charAt(j);
            freq.put(c, freq.get(c) - 1);
            
            while(i < n && freq.get('Q') <= k && freq.get('W') <= k && freq.get('E') <= k && freq.get('R') <= k) {
                ans = Math.min(ans, j - i + 1);
                char ci = s.charAt(i);
                freq.put(ci, freq.get(ci) + 1);
                ++i;
            }
        }
        return ans;
    }
}