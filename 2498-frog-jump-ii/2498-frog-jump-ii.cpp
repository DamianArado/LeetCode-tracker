class Solution {
public:
    // we shouldn't miss any rock in our path
    // this problem then boils down to finding the max difference between alternate stones 
    // in odd path and even path
    int maxJump(vector<int>& stones) {
        int maxDiff = stones[1] - stones[0], n = size(stones);
        for(int i = 2; i < n; i += 2) maxDiff = max(maxDiff, stones[i] - stones[i - 2]);
        for(int i = 3; i < n; i += 2) maxDiff = max(maxDiff, stones[i] - stones[i - 2]);
        return maxDiff;
    }
};