class Solution {
private:
    vector<int> primeFactors(int n) {
        vector<int> prime;
        while(n % 2 == 0) {
            prime.emplace_back(2);
            n = n / 2;
        }
        for(int i = 3; i <= sqrt(n); i += 2) {
            while(n % i == 0) {
                prime.emplace_back(i);
                n = n / i;
            }
        }
        if(n > 2) 
            prime.emplace_back(n);
        return prime;
    }
public:
    int smallestValue(int n) {
        while(n > 5) {
            vector<int> primes = primeFactors(n);
            if(primes.size() <= 1) 
                break;
            n = 0;
            for(int i = 0; i < size(primes); ++i) 
                n += primes[i];
        }
        return n;
    }
};