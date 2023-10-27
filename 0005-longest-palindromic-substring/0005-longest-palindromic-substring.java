class Solution {
    public String longestPalindrome(String s) {
        // spread from middle algorithm
        int n = s.length(), longestPalindromeLen = 1, longestPalindromeStart = 0;
        for (int i = 0; i < n; ++i) {
            int right = i, left = i - 1;
            // aaaa repetition
            while (right < n && s.charAt(i) == s.charAt(right))
                ++right;
            // this is the window length of the palindrome
            while (left >= 0 && right < n && s.charAt(left) == s.charAt(right)) {
                --left;
                ++right;
            }
            int palindromeLength = right - left - 1;
            if (palindromeLength > longestPalindromeLen) {
                longestPalindromeLen = palindromeLength;
                longestPalindromeStart = left + 1;
            }
        }
        return s.substring(
            longestPalindromeStart, longestPalindromeStart + longestPalindromeLen);
    }
}