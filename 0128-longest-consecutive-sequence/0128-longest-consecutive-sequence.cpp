class Solution {
public:
    /*
    
    ✔️ Solution - III (Using Hashset - w/ optimizations)

    We can form a solution without the need to spend time erasing elements from the hashset.

    Instead of taking the first element that we find in the hashset and iterating both forward and backward, we can just keep skipping till we find that hashset contains num - 1. Finally, we can just iterate in the forward direction till we find consecutive elements in hashset and update longest at the end
    
    */
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> s(begin(nums), end(nums));
        int longest = 0;
        for(const int &num : s) {
            if(s.count(num - 1)) continue;
            int j = 1;
            while(s.count(num + j)) ++j;
            longest = max(longest, j);
        }
        return longest;
    }
    // TC & SC - O(n)   
    
    /*
    ✔️ Solution - II (Using Hashset)

    We need to find the longest consecutive sequence in linear time. We can do this if we insert all the elements of nums into a hashset. Once we have inserted all the elements, we can just iterate over the hashset to find longest consecutive sequence involving the current element(let's call it num) under iteration. This can simply be done by iterating over elements that are consecutive to num till we keep finding them in the set. Each time we will also delete those elements from set to ensure we only visit them once.

    C++

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums)); // inserting all elements into hashset
        int longest = 0;
        for(auto& num : s) {
            int cur_longest = 1;
            // find consecutive elements in the backward and forward direction from num
            for(int j = 1; s.count(num - j); j++) s.erase(num - j), cur_longest++;
            for(int j = 1; s.count(num + j); j++) s.erase(num + j), cur_longest++;
            longest = max(longest, cur_longest);  // update longest to hold longest consecutive sequence till now
        }
        return longest;
    }*/
};