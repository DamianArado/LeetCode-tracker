class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0, right = size(people) - 1, boats = 0;
        sort(begin(people), end(people));
        while(left <= right) {
            if(people[left] + people[right] <= limit)
                ++left, --right;
            else --right;
            ++boats;
        }
        return boats;
    }
};