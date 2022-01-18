class Solution { // Using Moore's Voting Algorithm -> O(n) TC & O(1) SC
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, elem;
        for(int i = 0; i < nums.size(); ++i) {
            if(count == 0) elem = nums[i];
            if(elem == nums[i]) ++count;
            else --count;
        }
        return elem;
    }
};