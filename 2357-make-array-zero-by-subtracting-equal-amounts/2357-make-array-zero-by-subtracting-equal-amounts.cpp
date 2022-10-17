class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        return size(st) - st.count(0);
    }
};