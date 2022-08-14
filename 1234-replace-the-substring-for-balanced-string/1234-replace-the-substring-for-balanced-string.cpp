class Solution {
public:
    /*
    
    Here, we have to find the length of the smallest substring that we have to remove such that the frequency
    of each character 'Q', 'W', 'E' and 'R' is less than or equal to n / 4
    
    We will use 2 pointers start and end to find this minimum size window that can be removed in order to get
    the balanced string
              0 1 2 3 4 5 6 7 8 9 10 11 
    I/P: s = "Q Q R E R E W E R Q  Q  E "
    O/P: 2
    Explanation: 
    freq < char , int >
         <   Q  ,  4  > 
         <   W  ,  1  >
         <   E  ,  4  >
         <   R  ,  3  >
    
    Remove QE from index 10-11 and replace them with WW 
    to get Q W Q W E R E W R Q W W where each character appears exactly n / 4 times
    
    */
    int balancedString(string s) {
        int n = s.length(), k = n / 4;
        
        // count frequency of occurence
        unordered_map<char, int> freq;
        for(char &c : s) freq[c]++;
        
        // sliding window logic
        int start = 0, end = 0, ans = n;
        for(end = 0; end < n; ++end) {
            // reduce the frequency
            freq[s[end]]--;
            // if it satisfies the condition, that frequency of each character <= n / 4
            // update our answer and move the start index to find the better window
            // start < n due to the corner case QWER or multiples of it
            while(start < n and freq['Q'] <= k and freq['W'] <= k and freq['E'] <= k and freq['R'] <= k) {
                ans = min(ans, end - start + 1);
                freq[s[start]]++;
                start++;
            }
        }
        return ans;
    }
};