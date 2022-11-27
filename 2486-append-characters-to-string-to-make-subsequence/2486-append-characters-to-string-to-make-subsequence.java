class Solution {
    public int appendCharacters(String s, String t) {
        int j = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s.charAt(i) == t.charAt(j)) ++j;
            if(j == t.length()) return 0;
        }
        return t.length() - j;
    }
}