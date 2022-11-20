// class Solution {
// public:
//     int unequalTriplets(vector<int>& nums) {
//         int n = size(nums), count = 0;
//         for(int i = 0; i < n - 2; ++i) {
//             for(int j = i + 1; j < n - 1; ++j) {
//                 for(int k = j + 1; k < n; ++k) {
//                     if(nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]) 
//                         count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int &n : nums) mp[n]++;
        int left = 0, right = size(nums), ans = 0;
        for(auto &[n, cnt] : mp) {
            right -= cnt;
            ans += cnt * left * right;
            left += cnt;
        }
        return ans;
    }
};