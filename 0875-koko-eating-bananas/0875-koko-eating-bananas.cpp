class Solution {
private:
    bool canEat(vector<int> &piles, int expectedHrs, int k) {
        long long calculatedHrs = 0;
        for(const int &pile : piles) {
            calculatedHrs += pile / k;
            if(pile % k != 0) ++calculatedHrs;
        }
        return calculatedHrs <= expectedHrs;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // k can lie in the range: [1, max(piles[i])]
        // we can use binary search to check whether or not we can eat all bananas within h hours
        int left = 1, right = 0;
        for(const int &pile : piles) right = max(right, pile);
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(canEat(piles, h, mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};