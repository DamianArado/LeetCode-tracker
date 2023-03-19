typedef long long ll;
class Solution {
public:
    ll minimumTime(vector<int>& time, int totalTrips) {
        // range of binary search:
        // min: 0  - no totalTrips, max: min(time[i]) * totalTrips ; time taken such that we do all the trips using the fastest bus
        ll left = 0, right = 1e10;
        for(const int &t : time) right = min(right, (ll)t);
        right *= totalTrips;
        ll ans = right;
        while(left <= right) {
            ll mid = left + (right - left) / 2, trips = 0;
            // checking how many trips can we do by 'mid' time
            for(const int &t : time) trips += mid / t;
            if(trips >= totalTrips) {
                ans = min(ans, mid);
                right = mid - 1;
            } else left = mid + 1;
        }
        return ans;
    }
};