class Solution {
public:
    bool check(vector<int>& A) {
        for (int i = 0, k = 0; i < A.size(); ++i)
            if (A[i] > A[(i + 1) % A.size()] && ++k > 1)
                return false;
        return true;
    }
};