class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> majElem;
        int n = nums.size(), elem1 = -1, cnt1 = 0, elem2 = -1, cnt2 = 0;
        for(int num : nums) {
            if(num == elem1) {
                cnt1++;
            } else if(num == elem2) {
                cnt2++;
            } else if(cnt1 == 0) {
                elem1 = num;
                cnt1 = 1;
            } else if(cnt2 == 0) {
                elem2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int num : nums) {
            if(num == elem1) cnt1++;
            if(num == elem2) cnt2++;
        }
        if(cnt1 > n / 3) majElem.push_back(elem1);
        if(cnt2 > n / 3 and elem2 != elem1) majElem.push_back(elem2);
        return majElem;
    }
};