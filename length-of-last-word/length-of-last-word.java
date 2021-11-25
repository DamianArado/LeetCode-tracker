class Solution {
    public int lengthOfLastWord(String s) {
        int lastWordLen = 0;
        int currentWordLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                currentWordLen = 0;
            } else {
                currentWordLen++;
                lastWordLen = currentWordLen;
            }
        }
        return lastWordLen;
    }
}