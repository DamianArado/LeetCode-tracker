class Solution {
public:
    // If we calculate all distances between 4 points, 4 smaller distances should be equal (sides), and 2 
    // larger distances should be equal too (diagonals). As an optimization, we can compare squares of the 
    // distances, so we do not have to deal with the square root and precision loss.
    // Therefore, our set will only contain 2 unique distances in case of square (beware of the zero distance though).

    int d(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s({ d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4) });
        return !s.count(0) && s.size() == 2;
    }
};