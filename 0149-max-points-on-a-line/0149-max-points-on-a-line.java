class Solution {
    public int maxPoints(int[][] points) {
        int ans = 1;
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] x, int[] y) {
                if(x[0] == y[0]) return x[1] - y[1];
                return x[0] - y[0];
            }
        });
        for(int i = 0; i < points.length; ++i) {
            var m = new HashMap<Double, Integer>();
            for(int j = i + 1; j < points.length; ++j) {
                double x = ((double) (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]));
                double theta = Math.atan(x);
                m.put(theta, m.getOrDefault(theta, 0) + 1);
                ans = Math.max(ans, m.get(theta) + 1);
            }
        }
        return ans;
    }
}