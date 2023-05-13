typedef long long ll;
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        vector<ll> temp;
        const int MOD = 1e9 + 7;
        for(const int &i : nums)
            temp.emplace_back(i);
        
        sort(begin(temp), end(temp));
        ll  min = 0, sum = 0;
        for(int i = 0 ; i < size(temp); ++i) {
            sum = (sum +((temp[i] * temp[i]) % MOD) * temp[i] % MOD) % MOD;
            sum = (sum + ((min * temp[i]) % MOD) * temp[i] % MOD) % MOD;
            min =(min * 2) % MOD;
            min = (min + temp[i]) % MOD;
            
        }
        return sum % MOD;
    }
};