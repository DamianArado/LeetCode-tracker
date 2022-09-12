class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        int[][] engineer = new int[n][2];
        for(int i = 0; i < n; ++i) {
            engineer[i][0] = efficiency[i];
            engineer[i][1] = speed[i];
        }
        Arrays.sort(engineer, (a, b) -> a[0] - b[0]);
        var minHeap = new PriorityQueue<Integer>();
        long ans = 0, sum = 0;
        for(int i = n - 1; i >= 0; --i) {
            sum += engineer[i][1];
            minHeap.offer(engineer[i][1]);
            if(minHeap.size() > k)
                sum -= minHeap.poll();
            ans = Math.max(ans, sum * engineer[i][0]);
        }
        return (int)(ans % (int)(1e9 + 7));
    }
}