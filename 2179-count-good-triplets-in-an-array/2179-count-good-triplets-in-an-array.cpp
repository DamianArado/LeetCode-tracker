/*

We first use two arrays to get a single array with indexes:

A number in the first array is replaced with an index of that number in the second one.
Then, we compute good triplets in that array, such as i < j < k and nums1[i] < nums1[j] < nums1[k]. This is similar to 1534. Count Good Triplets.

For that, we go through each middle element, and count smaller elements on the left, and greater on the right. That middle element can form smaller * greater good triplets.

We can use BIT (AKA Fenwick Tree) to count elements smaller (sm) than the middle element in O(n log n). Because we have n - 1 unique numbers, figuring out greater (gr) elements on the right is easy.

*/

class Solution {
    constexpr int static n = 100000;
    int bt[n + 1] = {};
public:
    
    int prefix_sum(int i) {
        int sum = 0;
        for (i = i + 1; i > 0; i -= i & (-i))
            sum += bt[i];
        return sum;
    }
    
    void add(int i, int val) {
        for (i = i + 1; i <= n; i += i & (-i))
            bt[i] += val;
    }
    
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long res = 0, sz = nums1.size();
        vector<int> ids(sz);
        for (int i = 0; i < sz; ++i)
            ids[nums2[i]] = i;
        for (int i = 0; i < sz - 1; ++i) {
            int mid = ids[nums1[i]], sm = prefix_sum(mid), gr = sz - 1 - mid - (i - sm);
            res += (long long)sm * gr;
            add(mid, 1);
        }
        return res;
    }
    
};