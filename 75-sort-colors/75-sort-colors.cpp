// Dutch National Flag problem using 3 pointers
// We will have zeroes here: [0 : low - 1]
// Twos here: [high + 1 : n]
// Ones here: [low : mid - 1]
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size() - 1;
        // We'll have 3 checks here
        while(mid <= high) {
            switch(nums[mid]) {
                case 0:
                    swap(nums[low++], nums[mid++]);
                    break;
                case 1:
                    ++mid;
                    break;
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
    }
};