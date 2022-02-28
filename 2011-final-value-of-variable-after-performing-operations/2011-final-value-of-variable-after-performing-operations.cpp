class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for(int i = 0; i < operations.size(); ++i) {
            if(operations[i] == "--X" || operations[i] == "X--") val -= 1;
            else val += 1;
        }
        return val;
    }
};