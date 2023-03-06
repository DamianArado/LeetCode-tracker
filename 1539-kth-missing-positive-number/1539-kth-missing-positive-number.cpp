class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // brute force
        unordered_map<int, int> mp;
        for(int &i : arr) mp[i]++;
        int current = 1;
        while(k > 0) {
            if(!mp.count(current)) --k;
            ++current;
        }
        return current - 1;
    }
};