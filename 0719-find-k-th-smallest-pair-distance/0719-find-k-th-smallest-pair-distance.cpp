// brute forced TLE shit!
// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         priority_queue<int> maxHeap;
//         for(int i = 0; i < size(nums) - 1; ++i) {
//             for(int j = i + 1; j < size(nums); ++j) {
//                 int difference = abs(nums[j] - nums[i]);
//                 maxHeap.emplace(difference);
//                 if(maxHeap.size() > k) maxHeap.pop();
//             }
//         }
//         return maxHeap.top();
//     }
// };
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = size(nums);
        // Step 1: sort our array in ascending order - O(n logn)
        sort(begin(nums), end(nums));
        // Step 2: run a binary search on the search space: [minDist, maxDist]
        // where minDist is the minimum distance between any pair and maxDist is the max distance between them
        int minDist = 0, maxDist = nums[n - 1] - nums[0];
        while(minDist <= maxDist) {
            // using mid as a pivot to check which half is better in order to obtain the k-th min 
            // difference pair, it's like a guess for the min distance 
            // and after this we will see whether our pairs are greater than or less than this guess
            int midDist = minDist + (maxDist - minDist) / 2;
            int left = 0, right = 0, count = 0;
            while(right < n) {
                // if this distance is greater than pivot, we increase the window from left
                if(nums[right] - nums[left] > midDist) ++left;
                // if less or equal we count the pairs and increase the window from right
                else {
                    count += (right - left);
                    ++right;
                }
            }
            // if we have a lot more pairs than k, we discard the right half in order to keep the min ones
            if(count >= k) maxDist = midDist - 1;
            // if we have lesser pairs, we discard the left half
            else minDist = midDist + 1;
        }
        // by this time we would have got our k-th min distance pair
        return minDist;
    }
};