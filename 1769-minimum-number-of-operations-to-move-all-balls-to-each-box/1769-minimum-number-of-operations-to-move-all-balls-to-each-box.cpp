class Solution {
public:
    /*
    We first "move" balls from left to right, and track how many ops it takes for each box.

    For that, we count how many balls we got so far in cnt, and accumulate it in ops.

    Then, we do the same from right to left.
    */

    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.length()); 
        for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
           res[i] += ops;
           cnt += boxes[i] == '1' ? 1 : 0;
           ops += cnt;
        }
        for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        return res;
    }
};