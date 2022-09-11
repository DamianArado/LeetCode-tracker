class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxF = 0, ans = INT_MAX;
        bool flag = false;
        for(int num : nums) {
            if(num % 2 == 0) {
                flag = true;
                freq[num]++;
                maxF = max(maxF, freq[num]);
            }
        }
        for(int num : nums) {
            if(freq[num] == maxF and flag == true) {
                ans = min(num, ans);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};