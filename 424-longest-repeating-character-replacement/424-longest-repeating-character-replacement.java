class Solution {
    public int characterReplacement(String s, int k) {
        int n = s.length(), i = 0, maxFreq = 0, windowSize = 0;
        int[] freq = new int[26];
        for(int j = 0; j < n; ++j) {
            freq[s.charAt(j) - 'A']++;
            maxFreq = Math.max(maxFreq, freq[s.charAt(j) - 'A']);
            windowSize = j - i + 1;
            if(windowSize > maxFreq + k) {
                freq[s.charAt(i) - 'A']--;
                i++;
            }
        }
        return n - i;
    }
}