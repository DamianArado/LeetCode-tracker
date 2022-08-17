class Solution {
    public int edgeScore(int[] edges) {
        int n = edges.length;
        double maxScore = 0, ansNode = n + 1;
        double[] score = new double[n];
        for(int i = 0; i < n; ++i) {
            score[edges[i]] += i;
            maxScore = Math.max(maxScore, score[edges[i]]);
        }
        for(int i = 0; i < n; ++i) {
            if(score[i] == maxScore) {
                ansNode = i;
                break;
            }
        }
        return (int)ansNode;
    }
}