/***

If freq = 1, not possible
If freq = 2, needs just one 2-task
If freq = 3, needs just one 3-task
If freq = 3k, needs k batches of 3-task
If freq = 3k + 1, needs k - 1 batches of 3-task and 2 batches of 2-task
If freq = 3k + 2, needs k batches of 3-task and 1 batch of 2-task
Thus, ans = (freq + 2) / 3

*/
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(int &task : tasks) mp[task]++;
        for(auto &it : mp) {
            if(it.second == 1) return -1;
            else ans += (it.second + 2) / 3;
        }
        return ans;
    }
};