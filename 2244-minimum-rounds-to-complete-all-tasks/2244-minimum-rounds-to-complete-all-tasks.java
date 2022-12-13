class Solution {
    public int minimumRounds(int[] tasks) {
        int ans = 0;
        var freq = new HashMap<Integer, Integer>();
        for(int task : tasks) 
            freq.put(task, freq.getOrDefault(task, 0) + 1);
        for(int i : freq.values()) {
            if(i == 1) return -1;
            ans += (i + 2) / 3;
        }
        return ans;
    }
}