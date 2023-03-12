// Brute force: O(n) tc & O(n) sc
// class Solution {
// public:
//     int maxScore(vector<int>& nums) {
//         vector<double> aux(size(nums));
//         sort(begin(nums), end(nums));
//         reverse(begin(nums), end(nums));
//         aux[0] = nums[0];
//         for(int i = 1; i < size(nums); ++i) 
//             aux[i] = aux[i - 1] + nums[i];
//         int count = 0;
//         for(double &i : aux) if(i > 0) ++count;
//         return count;
//     }
// };
class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int count = 0, n = size(nums);
        double sum = 0;
        for(int i = n - 1; i >= 0; --i) {
            sum += nums[i];
            if(sum > 0) ++count;
            else break;
        }
        return count;
    }
};