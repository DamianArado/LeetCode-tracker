class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = size(nums1), n2 = size(nums2);
        if(n2 == 1) return {-1};

        // Step 1: find the next greater element for each nums2[i]
        stack<int> s;
        s.emplace(nums2[0]);
        int x = nums2[1];
        unordered_map<int, int> mp;
        for(int i = 1; i < n2; ++i) {
            x = nums2[i];
            if(x <= s.top()) s.emplace(x);
            else {
                while(!s.empty() and x > s.top()) {
                    mp[s.top()] = x;
                    s.pop();
                }
                s.emplace(x);
            }
        }
        while(!s.empty()) {
            mp[s.top()] = -1;
            s.pop();
        }
        // Step 2: use this result to fill answer for nums1 guys
        vector<int> res;
        for(int &num : nums1) res.emplace_back(mp[num]);
        return res;
    }
};