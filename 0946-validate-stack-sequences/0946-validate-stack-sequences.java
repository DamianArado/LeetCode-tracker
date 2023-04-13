class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        var s = new Stack<Integer>();
        int i = 0;
        for (int val : pushed) {
            s.push(val);
            while (!s.empty() && s.peek() == popped[i]) {
                ++i;
                s.pop();
            }
        }
        return s.isEmpty();
    }
}