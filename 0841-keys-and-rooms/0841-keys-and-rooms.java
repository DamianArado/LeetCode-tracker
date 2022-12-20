class Solution {
    private void dfs(int current, boolean[] visited, List<List<Integer>> rooms) {
        visited[current] = true;
        for(Integer adjRoom : rooms.get(current)) 
            if(visited[adjRoom] == false)
                dfs(adjRoom, visited, rooms);
    }
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        var visited = new boolean[n];
        dfs(0, visited, rooms);
        for(int i = 0; i < n; ++i) if(visited[i] == false) return false;
        return true;
    }
}