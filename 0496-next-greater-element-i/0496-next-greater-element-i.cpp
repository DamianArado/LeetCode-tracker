class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = size(nums1), n2 = size(nums2);
        if(n2 == 1) return {-1};
        // step 1: find NGE for each element in nums2
        stack<int> s;
        s.push(nums2[0]);
        unordered_map<int, int> m;  // for storing NGE
        int current = nums2[1]; // element which we will use to compare
        for(int i = 1; i < n2; ++i) {
            current = nums2[i];
            if(current > s.top())
                while(!s.empty() and current > s.top()) {  // can be NGE
                    m[s.top()] = current;
                    s.pop();
                }
            s.push(current); // keep pushing 
        }
        while(!s.empty()) {
            m[s.top()] = -1;  // they don't have any NGE
            s.pop();
        }
        // step 2: use this resultant map to calculate the result for nums1
        vector<int> ans;
        for(const int &num1 : nums1)
            ans.push_back(m[num1]);
        return ans;
    }
};