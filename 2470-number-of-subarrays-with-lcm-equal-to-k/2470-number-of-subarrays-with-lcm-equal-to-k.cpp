typedef long long int ll;
class Solution {
private:
    long long findLCM(ll x, ll y) {
        return (x / __gcd(x, y)) * y;
    }
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = size(nums), count = 0;
        for(int i = 0; i < n; ++i) {
            int lcm = nums[i];
            for(int j = i; j < n; ++j) {
                lcm = findLCM(lcm, nums[j]);
                if(lcm == k) ++count;
            }
        }
        return count;
    }
};