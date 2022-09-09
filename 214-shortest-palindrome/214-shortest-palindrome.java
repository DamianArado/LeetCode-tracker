class Solution {
    private int[] KMP(String text) {
        int[] kmp = new int[text.length() + 1];
        int i = 0, j = -1;
        kmp[0] = -1;
        while(i < text.length()) {
            while(j != -1 && text.charAt(i) != text.charAt(j))
                j = kmp[j];
            ++i;
            ++j;
            kmp[i] = j;
        }
        return kmp;
    }
    public String shortestPalindrome(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        String text = s + "#" + rev;
        int n = text.length();
        int[] kmp = KMP(text);
        int pos = kmp[n];
        String ans = s.substring(pos);
        String temp = new StringBuilder(ans).reverse().toString();
        ans = temp;
        return ans + s;
    }
}