/*
    Idea is ---
    As they said all numbers are distinct integers and We need to find out all possible subsets
    No of subsets would be (2 power, No_of_element[from the array])
    And how We are going to Find It Out ????
    Need To Run A loop From 0 to 2^No_of_element and for each number Find All Set Bit Positions Element from that array

    lets take An Example For better Understanding

    array = [1,2,3]
    No of subsets = 2^3 = 8
    from 0 to 8 for each value find setbit and put into an array

    No     BitRepresentation       Array         Ans_Array 
    0         [ 0 0 0 ]             []            {}                  ----->as There No Set Bit 

    1         [ 0 0 1 ]            [ 0 0 3]       {3}  

    2         [ 0 1 0 ]            [ 0 2 0]       {2}  

    3         [ 0 1 1 ]            [ 0 2 3]       {2,3}  

    4         [ 1 0 0 ]            [ 1 0 0]       {1}  

    5         [ 1 0 1 ]            [ 1 0 3]       {1,3}  

    6         [ 1 1 0 ]            [ 1 2 0]       {1,2}  

    7         [ 1 1 1 ]            [ 1 2 3]       {1,2,3}  

ANSWER - [{},{3},{2},{1},{1,3},{1,2},{1,2,3}] - --->return It
*/

// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        for (int i = 0; i < pow(2, nums.size()); ++i) {
            vector<int> subset;
            int msk = i, idx = 0;
            while(msk) {
                if(msk & 1) subset.emplace_back(nums[idx]);
                ++idx, msk >>= 1;
            }
            result.emplace_back(subset);
        }
        return result;
    }
};