class Solution {
public:

    // O(n^2 solution)

    int threeSumClosest(vector<int> &num, int target) {        
        vector<int> v(num.begin(), num.end()); // I didn't wanted to disturb original array

        int n = 0;
        int ans = 0;
        int sum;

        sort(v.begin(), v.end());

        // If less then 3 elements then return their sum
        while (v.size() <= 3) {
            return accumulate(v.begin(), v.end(), 0);
        }

        n = v.size();

        /* v[0] v[1] v[2] ... v[i] .... v[j] ... v[k] ... v[n-2] v[n-1]
         *                    v[i]  <=  v[j]  <= v[k] always, because we sorted our array. 
         * Now, for each number, v[i] : we look for pairs v[j] & v[k] such that 
         * absolute value of (target - (v[i] + v[j] + v[k]) is minimised.
         * if the sum of the triplet is greater then the target it implies
         * we need to reduce our sum, so we do K = K - 1, that is we reduce
         * our sum by taking a smaller number.
         * Simillarly if sum of the triplet is less then the target then we
         * increase out sum by taking a larger number, i.e. J = J + 1.
         */
        ans = v[0] + v[1] + v[2];

        for (int i = 0; i < n-2; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                sum = v[i] + v[j] + v[k];
                if (abs(target - ans) > abs(target - sum)) {
                    ans = sum;
                    if (ans == target) return ans;
                }
                (sum > target) ? k-- : j++;
            }
        }
        return ans;
        }
};