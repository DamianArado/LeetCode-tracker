class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> majorityElements;
        int sz = nums.size();
        int elem1 = -1, elem2 = -1, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < sz; ++i) {
            if(nums[i] == elem1) {
                ++cnt1;
            } else if(nums[i] == elem2) {
                ++cnt2;
            } else if(cnt1 == 0) {
                elem1 = nums[i]; 
                cnt1 = 1;
            } else if(cnt2 == 0) {
                elem2 = nums[i]; 
                cnt2 = 1;
            } else {
                --cnt1; 
                --cnt2;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < sz; ++i) {
            if(nums[i] == elem1) ++cnt1;
            if(nums[i] == elem2) ++cnt2;
        }
        if(cnt1 > sz / 3) majorityElements.emplace_back(elem1);
        if(cnt2 > sz / 3 && elem2 != elem1) majorityElements.emplace_back(elem2);
        return majorityElements;
    }
};