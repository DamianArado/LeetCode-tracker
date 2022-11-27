// brute forced xD
// class Solution {
// private:
//     int findMedian(vector<int> &nums, int start, int end) {
//         vector<int> aux;
//         for(int i = start; i <= end; ++i) aux.emplace_back(nums[i]);
//         sort(aux.begin(), aux.end());
//         int mid = (size(aux) % 2 == 0 ? (size(aux) / 2) - 1 : size(aux) / 2);
//         return aux[mid];
//     }
// public:
//     int countSubarrays(vector<int>& nums, int k) {
//         int ans = 0;
//         for(int i = 0; i < size(nums); ++i) {
//             for(int j = i; j < size(nums); ++j) {
//                 if(findMedian(nums, i, j) == k) {
//                     cout << i << " " << j << endl;
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = size(nums), sum = 0, ans = 0;
        bool flag = false;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int &num : nums) {
            if(num < k) --sum;
            else if(num > k) ++sum;
            else if(num == k) flag = true;
            if(flag) ans += mp[sum] + mp[sum - 1];
            else mp[sum]++;
        }
        return ans;
    }
};