class Solution {
public:
    int peakIndexInMountainArray(vector<int> A) {
       return max_element(A.begin(), A.end()) - A.begin();
    }
};