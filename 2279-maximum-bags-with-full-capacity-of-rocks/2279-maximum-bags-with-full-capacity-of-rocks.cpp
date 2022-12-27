class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = size(capacity);
        // Step 1: create a ds based on the format [capacity, rocks, space available]
        vector<int> bag(n);
        for(int i = 0; i < n; ++i)
            bag[i] = capacity[i] - rocks[i];
        // Step 2: sort them on the basis of increasing space available
        sort(begin(bag), end(bag));
        // Step 3: now assign rocks and count the number of bags
        int bags = 0;
        for(int i = 0; i < n; ++i) {
            if(additionalRocks < 0) break;
            else if(additionalRocks >= bag[i]) {
                additionalRocks -= bag[i];
                bags++;
            }
        }
        return bags;
    }
};