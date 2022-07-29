class Solution {
    public String minWindow(String s, String t) {
        int n = s.length(), i = 0, minLen = Integer.MAX_VALUE, start = 0;
        HashMap<Character, Integer> freq = new HashMap<>();
        for(int it = 0; it < t.length(); ++it) {
            if(freq.containsKey(t.charAt(it)))
                freq.put(t.charAt(it), freq.get(t.charAt(it)) + 1);
            else
                freq.put(t.charAt(it), 1);
        }
        int chars = freq.size();
        for(int j = 0; j < n; ++j) {
            if(freq.containsKey(s.charAt(j))) {
                freq.put(s.charAt(j), freq.get(s.charAt(j)) - 1);
                if(freq.get(s.charAt(j)) == 0) chars--;
            }
            if(chars == 0) {
                while(chars == 0) {
                    if(freq.containsKey(s.charAt(i))) {
                        freq.put(s.charAt(i), freq.get(s.charAt(i)) + 1);
                        if(freq.get(s.charAt(i)) == 1) chars++;
                        int windowSize = j - i + 1;
                        if(windowSize < minLen) {
                            minLen = windowSize;
                            start = i;
                        }
                    }
                    i++;
                }
            }
        }
        return minLen == Integer.MAX_VALUE ? "" : s.substring(start, start + minLen);
    }
}