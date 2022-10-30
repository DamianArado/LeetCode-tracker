class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int seed = INT_MAX, maxRemainder = 0;
        unordered_map<int, int> remFreq;
        for(int &num : nums) {
            int remainder = num % space;
            remFreq[remainder]++;
            if(maxRemainder < remFreq[remainder]) maxRemainder = remFreq[remainder];
        }
        for(int &num : nums) 
            if(remFreq[num % space] == maxRemainder) 
                seed = min(seed, num);
        return seed;
    }
};