class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums) {
            mp[num]++;
            if(mp[num] == 2) return true;
        }
        return false;
    }
};