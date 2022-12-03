class Solution {
    public int findMinArrowShots(int[][] points) {
        int n = points.length;
        if(n == 1) return 1;
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
        int arrows = 1, arrowEnd = points[0][1];
        for(int i = 1; i < n; ++i) {
            if(arrowEnd < points[i][0]) {
                ++arrows;
                arrowEnd = points[i][1];
            }
        }
        return arrows;
    }
}