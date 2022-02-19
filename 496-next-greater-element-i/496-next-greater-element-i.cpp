// Used Monotonically-decreasing stack: TC & SC -> O(nums1.size() + nums2.size())
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ans; // to store the value of next greater element
        stack<int> st; // monotonically decreasing (bottom -> top)
        int n = nums2.size() - 1; 
        
        // Traversing the list from right since we want to find the next greater element
        for(int i = n; i >= 0; --i) {
            // If we found a number smaller than given element at top of stack, pop it 
            while(!st.empty() && st.top() <= nums2[i]) st.pop(); 
            // If we found a number greater than the element at top of stack, ans for that number = top of stack
            if(!st.empty()) ans[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        
        vector<int> out;
        for(int num : nums1) {
            // If the key exists in the map, add the ans for key in the vector
            if(ans.count(num)) out.emplace_back(ans[num]);
            else out.emplace_back(-1);  // else add -1
        }
        return out;
    }
};