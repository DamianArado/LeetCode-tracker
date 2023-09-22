class Solution {
    public boolean isSubsequence(String s, String t) {
        int idx1 = 0, idx2 = 0, n1 = s.length(), n2 = t.length();
        while (idx1 < n1 && idx2 < n2) {
            if (s.charAt(idx1) == t.charAt(idx2)) {
                ++idx1; 
                ++idx2;
            } else 
                ++idx2;
        }
        return idx1 == n1;
    }
}