class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            long long int cnt = 0, cnt1 = 0;
            for(int j = 0; j < arr1.size(); j++) {
                if((arr1[j] & (1<<i)) != 0)
                    cnt++;
            }
            for(int j = 0; j < arr2.size(); j++) {
                if((arr2[j] & (1<<i)) != 0)
                    cnt1++;
            }
            cnt = cnt * cnt1;
            if(cnt & 1)
                ans += (1<<i);
        }
        return ans;
    }
};