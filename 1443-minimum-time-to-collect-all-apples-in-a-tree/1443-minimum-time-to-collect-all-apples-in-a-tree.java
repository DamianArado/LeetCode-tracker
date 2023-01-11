class Solution {
    private int dfs(int current, int parent, List<List<Integer>> g, List<Boolean> hasApple) {
        int total = 0; 
        for(int adjNode : g.get(current)) {
            if(adjNode == parent) continue;
            total += dfs(adjNode, current, g, hasApple);
        }
        if(current != 0 && (total > 0 || hasApple.get(current) == true))
            total += 2;
        return total;
    }
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        List<List<Integer>> g = new ArrayList<>();
        for(int i = 0; i < n; ++i)
            g.add(new ArrayList<>());
        for(int[] edge : edges) {
            g.get(edge[0]).add(edge[1]);
            g.get(edge[1]).add(edge[0]);
        }
        return dfs(0, 0, g, hasApple);
    }
}