class Solution {
    private static void dfs(int current, boolean[] visited, int[][] isConnected, int n) {
        visited[current] = true;
        for(int i = 0; i < n; ++i)
            if(visited[i] == false && isConnected[current][i] == 1)
                dfs(i, visited, isConnected, n);
    }
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length, components = 0;
        boolean[] visited = new boolean[n];
        // lets perform DFS to calculate the no. of components
        for(int i = 0; i < n; ++i) {
            if(visited[i] == false) {
                dfs(i, visited, isConnected, n);
                components += 1;
            }
        }
        return components;
    }
}