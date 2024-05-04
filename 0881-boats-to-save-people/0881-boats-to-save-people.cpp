class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        int l = 0, r = size(people) - 1, boats = 0;
        while (l <= r) {
            int weight = people[l] + people[r];
            if (weight <= limit)
                // both can go together
                ++boats, ++l, --r;
            else 
                // heaviest go alone
                ++boats, --r;
        }
        return boats;
    }
};