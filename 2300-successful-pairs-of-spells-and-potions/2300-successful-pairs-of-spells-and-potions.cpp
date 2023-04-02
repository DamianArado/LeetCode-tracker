class Solution {
private:
    int binarySearch(vector<int> &potions, const int &spell, long long &success) {
        int start = 0, end = size(potions) - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            long long product = ((long long) potions[mid] * spell);
            if(product < success) start = mid + 1;
            else end = mid - 1;
        }
        return end;
    }
public:
    // x log y TC : x = size(spells), y = size(potions)
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // step 1: sort the potions array
        sort(begin(potions), end(potions));
        vector<int> pairs;
        int sz = size(potions);
        for(const int &spell : spells) {
            // find the smallest element inside potions that when multiplied with spell >= success
            int idx = binarySearch(potions, spell, success);
            int numPairs = sz - idx - 1; 
            pairs.emplace_back(numPairs);
        }
        return pairs;
    }
};