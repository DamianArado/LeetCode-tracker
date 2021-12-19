class Solution {
public:
    int kthFactor(int n, int k) {
        vector<long int> factors;
        
        for(int i = 1; i <= n; i++) {
            if(n % i == 0)
                factors.emplace_back(i);
        }
        if(factors.size() == 0 || k - 1 < 0 || k > factors.size())
            return -1;
        else 
            return factors[k - 1];
    }
};