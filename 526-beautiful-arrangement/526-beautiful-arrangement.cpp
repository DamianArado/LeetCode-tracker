class Solution {
private:
    int dfs(int N, int i, vector<bool>& used) {
        if(i > N) return 1; // term. cond.
        int sum = 0;
        for(int num = 1; num <= N; ++num) {
            if(used[num]) continue;
            if(num %i != 0 && i % num != 0) continue; // co-prime
            used[num] = true;
            sum += dfs(N, i + 1, used);
            used[num] = false;
        }
        return sum;
    }
public:
    int countArrangement(int N) {
        if(N < 1) return 0;
        vector<bool> used(N + 1, false);
        return dfs(N, 1, used);
    }
};