class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int low = 0, high = A.size() - k;
        
        while (low < high) {
            int mid = (low + high) / 2;
            
            if (x - A[mid] > A[mid + k] - x)
                low = mid + 1;
            else
                high = mid;
        }
        
        return vector<int>(A.begin() + low, A.begin() + low + k);
    }
};