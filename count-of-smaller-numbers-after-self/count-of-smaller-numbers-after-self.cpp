class Solution {
public:
    #define iterator vector<vector<int>>::iterator
    void sort_count(iterator l, iterator r, vector<int>& count) {
        if (r - l <= 1) return;
        iterator m = l + (r - l) / 2;
        
        sort_count(l, m, count);
        sort_count(m, r, count);
        
        for (iterator i = l, j = m; i < m; i++) {
            while (j < r && (*i)[0] > (*j)[0]) ++j;
            count[(*i)[1]] += j - m; // add the number of valid "j"s to the indices of *i
        }
        inplace_merge(l, m, r);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<vector<int>> hold;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) 
            hold.push_back(vector<int>({nums[i], i})); // "zip" the nums with their indices
        
        vector<int> count(n, 0);
        sort_count(hold.begin(), hold.end(), count);
        return count;
    }
};