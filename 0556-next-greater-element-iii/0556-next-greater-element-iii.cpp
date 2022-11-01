class Solution {
public:
    int nextGreaterElement(int n1) {
        string n0 = to_string(n1);
        int n = n0.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (n0[k] < n0[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(n0.begin(), n0.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (n0[l] > n0[k]) {
                    break;
                }
            } 
    	    swap(n0[k], n0[l]);
    	    reverse(n0.begin() + k + 1, n0.end());
        }
        return stoll(n0) == n1 || stoll(n0) > INT_MAX || stoll(n0) < n1 ? -1 : stoll(n0);
    }
};