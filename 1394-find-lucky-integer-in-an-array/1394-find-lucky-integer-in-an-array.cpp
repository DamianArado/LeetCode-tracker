class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> count;
        for(const int &num : arr) count[num]++;
        int ans = -1;
        for(const int &num : arr)
            if(num == count[num] and num > ans)
                ans = num;
        return ans;
    }
};