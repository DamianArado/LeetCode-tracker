class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circular = 0, square = 0;
        for (const int &student : students)
            student == 0 ? ++circular : ++square;
        for (const int &sandwich : sandwiches) {
            if (!sandwich and !circular) return square;
            if (sandwich and !square) return circular;
            sandwich == 0 ? --circular : --square;
        }
        return 0;
    }
};