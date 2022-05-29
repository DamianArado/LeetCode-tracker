class Solution {
    private static boolean checkBipartite(int current, int[][] graph, int[] color) {
        if(color[current] == -1)
            color[current] = 1;
        for(int adj : graph[current]) {
            if(color[adj] == -1) {
                color[adj] = 1 - color[current];
                if(checkBipartite(adj, graph, color) == false)
                    return false;
            } else if(color[adj] == color[current]) 
                return false;
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int color[] = new int[n];
        for(int i = 0; i < n; ++i) 
            color[i] = -1;
        for(int i = 0; i < n; ++i) {
            if(checkBipartite(i, graph, color) == false)
                return false;
        }
        return true;
    }
}