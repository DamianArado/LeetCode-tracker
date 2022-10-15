class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> minPowersOf2, ans;
        for(int i = 0; i < 32; ++i)
            if(n & (1 << i)) 
                minPowersOf2.emplace_back(1 << i);
        for(int i = 0; i < size(queries); ++i) {
            long prod = 1;
            for(int j = queries[i][0]; j <= queries[i][1]; ++j)
                prod = (prod * minPowersOf2[j]) % 1000000007;
            ans.emplace_back(prod);
        }
        return ans;
    }
};