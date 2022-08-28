class Solution {
    public String removeStars(String s) {
        var st = new Stack<Character>();
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) != '*') st.push(s.charAt(i));
            else st.pop();
        }
        String ans = "";
        while(!st.empty()) {
            ans += st.peek();
            st.pop();
        }
        String reversed = new StringBuilder(ans).reverse().toString();
        return reversed;
    }
}