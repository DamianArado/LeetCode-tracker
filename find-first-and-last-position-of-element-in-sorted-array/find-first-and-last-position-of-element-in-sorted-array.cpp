class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    auto it1 = std::lower_bound(nums.begin(), nums.end(), target);
    auto it2 = std::lower_bound(nums.begin(), nums.end(), target + 1);
    if (it1 != nums.end() && *it1 == target) 
        return {static_cast<int>(it1 - nums.begin()), static_cast<int>(it2 - nums.begin() - 1)};
    return {-1, -1};
}
};