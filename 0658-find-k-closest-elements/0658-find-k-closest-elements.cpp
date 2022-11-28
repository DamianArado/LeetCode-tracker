/*

Intuition:

If we needed to find the closest element to x in arr, we could have done it in O(log n) time.
But here, since, we have to find k elements near x we can again solve it in O(log n) by finding the range
of size k where the elements nearest to x will lie.

Therefore, we start by discarding one part of the array completely by comparing the distance of it
from x, 
for e.x., if x - arr[mid] < arr[mid] + k - x: we discard the right side else the left side

*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0, end = size(arr) - k;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(x - arr[mid] <= arr[mid + k] - x) 
                end = mid;
            else start = mid + 1;
        }
        return vector<int>(begin(arr) + start, begin(arr) + start + k);
    }
};