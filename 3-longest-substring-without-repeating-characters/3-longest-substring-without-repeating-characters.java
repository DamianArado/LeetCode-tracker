class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), i = 0, maxLen = 0;
        HashMap<Character, Integer> freq = new HashMap<>();
        for(int j = 0; j < n; ++j) {
            if(freq.containsKey(s.charAt(j))) 
                freq.put(s.charAt(j), freq.get(s.charAt(j)) + 1);
            else 
                freq.put(s.charAt(j), 1);
            int windowSize = j - i + 1;
            if(freq.size() < windowSize) {
                freq.put(s.charAt(i), freq.get(s.charAt(i)) - 1);
                if(freq.get(s.charAt(i)) == 0) 
                    freq.remove(s.charAt(i));
                i++;
            } else {
                maxLen = Math.max(maxLen, windowSize);
            }
        }
        return maxLen;
    }
}