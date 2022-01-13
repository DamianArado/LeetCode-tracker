class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> nos;
        string ans = "";
        // storing factorial of n numbers [1,2,3...n] and building an array of potential candidates needed to 
        // build the permutations
        for(int i = 1; i < n; ++i) {
            fact *= i;
            nos.emplace_back(i);
        }
        nos.emplace_back(n);
        // we consider factorials from index 0, hence decreasing it here
        --k;
        while(true) {
            /*
             * For example: n = 3 and k = 4 (our 3rd permutation)
             * arr: [1,2,3] and k = 3 
             *
             * No. of permutations starting with each of 1, 2 and 3 are 2! (= 2)
             * So, we do a k/fact (3/2 = 1st), so we chose 2 _ _ 
             * Now, k = 1 (3%2), fact = 2/2 = 1 and we erased nos[0+1] which was indeed 2.
             *
             * No. of permutations starting with 1 and 3 are 1 each.
             * So, we do a k/fact (1/1 = 1st), so we chose 2 3 _
             * Now, k = 0 (1%1), fact = 1/1 = 1, and we erased nos[0+1] which was indeed 3.
             *
             * Hence, at last we added 1, and our required permutation became: [2,3,1]
             */
            ans += to_string(nos[k / fact]);
            nos.erase(nos.begin() + k / fact);
            if(nos.size() == 0) break;
            k %= fact;
            fact /= nos.size();
        }
        return ans;
    }
};