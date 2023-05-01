class Solution {
public:
    double average(vector<int>& salary) {
        int minSalary = INT_MAX, maxSalary = INT_MIN, sumSalary = 0, n = size(salary);
        for(const int &s : salary) {
            minSalary = min(minSalary, s);
            maxSalary = max(maxSalary, s);
            sumSalary += s;
        }
        sumSalary = sumSalary - minSalary - maxSalary;
        return ((double)sumSalary / (n - 2)); 
    }
};