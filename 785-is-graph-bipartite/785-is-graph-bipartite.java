class Solution {
    private static boolean isBipartiteDFS(int current, int[][] graph, int[] color) {
        if(color[current] == -1) color[current] = 1;
        for(int adjNode : graph[current]) {
            if(color[adjNode] == -1) {
                color[adjNode] = 1 - color[current];
                if(!isBipartiteDFS(adjNode, graph, color)) 
                    return false;
            } else if(color[adjNode] == color[current]) return false;
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        for(int i = 0; i < n; ++i) color[i] = -1;
        for(int i = 0; i < n; ++i) 
            if(color[i] == -1 && !isBipartiteDFS(i, graph, color))
               return false;
        return true;
    }
}