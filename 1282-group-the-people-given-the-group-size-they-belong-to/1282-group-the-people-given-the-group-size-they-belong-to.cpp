class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;
        vector<vector<int>> ans;
        for (int i = 0; i < size(groupSizes); ++i)
            mp[groupSizes[i]].emplace_back(i);
        for (const auto &[groupSize, candidates] : mp) {
            int n = size(candidates), partitions = n / groupSize, k = 0;
            for (int i = 0; i < partitions; ++i) {
                vector<int> group(groupSize);
                for (int j = 0; j < groupSize; ++j) 
                    group[j] = candidates[k++];
                ans.emplace_back(group);
            }
        }
        return ans;
    }
};