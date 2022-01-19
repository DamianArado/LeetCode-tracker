/*

Basic on this idea, I tried to arrange an ideal permutation.
Then I found that to place number i
I could only place i at A[i-1], A[i] or A[i+1].
So it came up to me,
It will be easier just to check if all A[i] - i equals to -1, 0 or 1

*/
class Solution {
public:
    /*
    The problem asks us to find whether the number of global inversions are equal to local inversion.
    And we know all local inversion are global. Why? .Because local inversions are basically gobal 
    with a distance as one between them.So if we can find at least one global inversion which is 
    not local our job is done and we can eliminate by returning false.
    And since we are maintaining the maximum value all the cases will be covered in it.
    */
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            if (abs(nums[i] - i) > 1) return false;
        return true;
    }
};