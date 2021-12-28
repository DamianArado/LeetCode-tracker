/*
    If a subarray is divisible by K, it has to be a multiple of K

    a-b=n*k, a = running total, b = any previous subarray sum, same as original prefix sum problems.

    We want to solve for b, so using basic algebra, b=a-n*k

    We don't know what n is, so we can get rid of n by modding every element by k
    (b%k) = (a%k) - (n*k)%k

    since n*k is a multiple of k and k goes into it evenly, the result of the (n *k)%k will be 0

    therefore
    b%k = a%k

    is the same as the formula we defined earlier, a-b=n*k

    where b = running total, a = any previous subarray sum

    So we just have to see if running total mod k is equal to any previous running total mod k
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> count(K);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (int a : A) {
            prefix = (prefix + a % K + K) % K;
            res += count[prefix]++;
        }
        return res;
    }
};