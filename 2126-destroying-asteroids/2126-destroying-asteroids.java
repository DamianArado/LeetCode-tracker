class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        long current = mass;
        for(int i = 0; i < asteroids.length; ++i) {
            if(current < asteroids[i]) return false;
            current += asteroids[i];
        }
        return true;
    }
}