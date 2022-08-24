class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long current = mass;
        for(int i = 0; i < size(asteroids); ++i) {
            if(current < asteroids[i]) return false;
            current += asteroids[i];
        }
        return true;
    }
};